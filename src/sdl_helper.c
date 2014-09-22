#include "sdl_helper.h"

SDL_Surface * surface;
Uint32 sdlh_current_time;
Uint32 sdlh_previous=0;

int sdlh_screen_width;
int sdlh_screen_height;
int sdlh_max_fps;
#define SCREEN_DEPTH 24
	
int sdlh_ms_per_frame;
void SDLH_StartSDL(int w,int h,int fps,const char * title)
{
	sdlh_screen_width=w;
	sdlh_screen_height=h;
	sdlh_max_fps=fps;
	sdlh_ms_per_frame=1000/sdlh_max_fps;
	
    SDL_Init(SDL_INIT_VIDEO);
    sdlh_current_time=SDL_GetTicks();
    sdlh_previous=0;
    surface = SDL_SetVideoMode(sdlh_screen_width, sdlh_screen_height, SCREEN_DEPTH, SDL_SWSURFACE /*| SDL_FULLSCREEN*/ );
    SDL_WM_SetCaption(title, title);
}

void SDLH_QuitSDL()
{
	SDL_Quit();
}

void SDLH_LimitFps()
{
		int sleep_needed;
		sdlh_previous=sdlh_current_time;
		sdlh_current_time=SDL_GetTicks();
		sleep_needed=sdlh_ms_per_frame-(sdlh_current_time-sdlh_previous);
		if (sleep_needed>0)
		{
			usleep(sleep_needed * 1000);
			sdlh_current_time=SDL_GetTicks();
		}
}

void SDLH_DrawStart()
{
	SDL_LockSurface(surface);
	SDL_FillRect(surface, NULL, 0x000000);
}
void SDLH_DrawEnd()
{
	SDL_UnlockSurface(surface);
	SDL_Flip(surface);
}



void SDLH_DrawPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
    Uint8 * pixel = (Uint8*)surface->pixels;
    pixel += (y * surface->pitch) + (x * (sizeof(Uint8) * 3));
    pixel[2] = r;
    pixel[1] = g;
    pixel[0] = b;
}





sdl_image SDLH_LoadImage(const char * path)
{
    sdl_image img;
    SDL_Surface *temp;


    temp = IMG_Load(path);
    if (temp == NULL)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return NULL;
    }
    img = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 255, 255, 255)); //Make white transparent. More efficient than a whole alpha channel!

    return img;
}






void SDLH_DrawImage(sdl_image image,int x,int y)
{
    SDL_Rect src, dest;
    src.x = 0;
    src.y = 0;
    src.w = image->w;
    src.h = image->h;

    dest.x = x;
    dest.y = y;
    dest.w = image->w;
    dest.h = image->h;

    SDL_BlitSurface(image, &src, surface, &dest);
}
