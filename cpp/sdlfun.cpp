#include "sdlfun.h"
SDL_Surface * cSdlh::s_surface=0;
Uint32 cSdlh::s_currentTime=0;
Uint32 cSdlh::s_previousTime=0;
int cSdlh::s_screenWidth=0;
int cSdlh::s_screenHeight=0;
int cSdlh::s_maxFps=0;
int cSdlh::s_msPerFrame=0;

#define SCREEN_DEPTH 24
	

void cSdlh::StartSDL(int w,int h,int fps,const char * title,bool fullscreen)
{
	s_screenWidth=w;
	s_screenHeight=h;
	s_maxFps=fps;
	s_msPerFrame=1000/s_maxFps;
	
    SDL_Init(SDL_INIT_VIDEO);
    s_currentTime=SDL_GetTicks();
    s_previousTime=0;
    if (fullscreen==false)
		s_surface = SDL_SetVideoMode(s_screenWidth, s_screenHeight, SCREEN_DEPTH, SDL_SWSURFACE);
    else
		s_surface = SDL_SetVideoMode(s_screenWidth, s_screenHeight, SCREEN_DEPTH, SDL_SWSURFACE | SDL_FULLSCREEN );
    SDL_WM_SetCaption(title, title);
}

void cSdlh::QuitSDL()
{
	SDL_Quit();
}

void cSdlh::LimitFps()
{
		int sleepNeeded;
		s_previousTime=s_currentTime;
		s_currentTime=SDL_GetTicks();
		sleepNeeded=s_msPerFrame-(s_currentTime-s_previousTime);
		if (sleepNeeded>0)
		{
			usleep(sleepNeeded * 1000);
			s_currentTime=SDL_GetTicks();
		}
}

void cSdlh::DrawStart()
{
	SDL_LockSurface(s_surface);
}

void cSdlh::ClearScreen()
{
	SDL_FillRect(s_surface, NULL, 0x000000);
}

void cSdlh::DrawEnd()
{
	SDL_UnlockSurface(s_surface);
	SDL_Flip(s_surface);
}



void cSdlh::DrawPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
    Uint8 * pixel = (Uint8*)s_surface->pixels;
    pixel += (y * s_surface->pitch) + (x * (sizeof(Uint8) * 3));
    pixel[2] = r;
    pixel[1] = g;
    pixel[0] = b;
}





SdlhImage cSdlh::LoadImage(const char * path)
{
    SdlhImage img;
    SDL_Surface * temp;


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






void cSdlh::DrawImage(SdlhImage image,int x,int y)
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

    SDL_BlitSurface(image, &src, s_surface, &dest);
}
