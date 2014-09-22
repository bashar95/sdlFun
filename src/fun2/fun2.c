//apt-get install libsdl-image1.2-dev libsdl-dev
#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768
#define SCREEN_DEPTH 24
//DO NOT CHANGE DEPTH
#define MAX_FPS 90
#include "fun2.h"

int MS_PER_FRAME=1000/MAX_FPS;
SDL_Surface * surface;
SDL_Surface * pre_surface;

///////////////////////////////////////////////////

void make_some_pixel_mess();
double half_pi;
double pi;
double tau;
double theta=0;
double theta_delta=0.1;

int main(int argc, char *argv[])
{
	half_pi=pi/2.0;
    prepare_sdl();
    make_some_pixel_mess();
    start_animating_until_stopped(); //matrix rotation
    SDL_Quit();
    return 0;
}

void make_some_pixel_mess()
{
	int x,y;
  	pre_surface=SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH,
                                   0, 0, 0, 0);

	for (x=0; x<SCREEN_WIDTH; x++)
	{
	    for (y=0; y<SCREEN_HEIGHT; y++)
	    {
		draw_pixel(pre_surface,x,y,x%255,y%255,(x+y)%255);
	    }
	}
	draw_image(surface,pre_surface,0,0);
	SDL_Flip(surface);
}


void prepare_sdl()
{
    SDL_Init(SDL_INIT_VIDEO);
    surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, SDL_SWSURFACE /*| SDL_FULLSCREEN*/ );
    SDL_WM_SetCaption("SDL Renderer", "Safwat");
}

void start_animating_until_stopped()
{
	Uint32 current_time=SDL_GetTicks();
	Uint32 previous_time=0;


	while (1)
	{
		animate_rotate_screen();
		if (handle_input()) return;
		limit_fps(&current_time,&previous_time);
	}
}


double safwat_cos(double x)
{
	return safwat_sin(half_pi-x);
}
void animate_rotate_screen()
{
	int x,y;
	int xm,ym; //x on math axes (screenwidth/0.5 is 0)
	double newx,newy;
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
	for (x=0; x<SCREEN_WIDTH; x++)
	{
	    for (y=0; y<SCREEN_HEIGHT; y++)
	    {

    		Uint8 * old_pixel = (Uint8*)pre_surface->pixels;
    		old_pixel += (y * pre_surface->pitch) + (x * (sizeof(Uint8) * 3));
		if (old_pixel[2]==0 && old_pixel[1]==0 && old_pixel[0]==0) continue;
		
		//REAL CODE
		//xm=x-SCREEN_WIDTH/2;
		//ym=SCREEN_HEIGHT/2-y;
		//newx=(xm*safwat_cos(theta)-ym*safwat_sin(theta)) + (SCREEN_WIDTH/2)  ;
		//newy=SCREEN_HEIGHT/2-(xm*safwat_sin(theta)+ym*safwat_cos(theta));

		//Just a Speed test, it has shown that safwat_sin and safwat_cos really suck at speed.
		xm=x-SCREEN_WIDTH/2;
		ym=SCREEN_HEIGHT/2-y;
		newx=(xm*theta-ym*theta) + (SCREEN_WIDTH/2);
		newy=SCREEN_HEIGHT/2-(xm*theta+ym*theta);
		if (newy<0 || newy>=SCREEN_HEIGHT) continue;
		if (newx<0 || newx>=SCREEN_WIDTH) continue;

		draw_pixel(surface,newx,newy,old_pixel[2],old_pixel[1],old_pixel[0]);
	    }
	}
	//draw_image(pre_surface,surface,0,0); //copy surface to pre_surface
	SDL_Flip(surface);
	theta+=theta_delta;
	if (theta>tau) theta=0;
}

int handle_input()
{
	SDL_Event event;
	while ( SDL_PollEvent(&event) )
	{
	    switch (event.type)
	    {
	    case SDL_MOUSEMOTION:
		//random=random_function(event.motion.x);
		break;
	    //case SDL_MOUSEMOTION:
	    //case SDL_MOUSEBUTTONDOWN:
	    case SDL_KEYDOWN:
	    case SDL_QUIT:
	        return 1;
	    }
    	}
}
void limit_fps(Uint32 * current_time,Uint32 * previous_time)
{
		int sleep_needed;
		*previous_time=*current_time;
		*current_time=SDL_GetTicks();
		sleep_needed=MS_PER_FRAME-(*current_time-*previous_time);
		//printf("%d - %d %d\n",sleep_needed,*previous_time,*current_time);
		if (sleep_needed>0)
		{
			usleep(sleep_needed * 1000);
			*current_time=SDL_GetTicks();
		}
}
