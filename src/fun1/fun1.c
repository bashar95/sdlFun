//apt-get install libsdl-image1.2-dev libsdl-dev
#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768
#define SCREEN_DEPTH 24
//DO NOT CHANGE DEPTH
#define MAX_FPS 90
#include "fun1.h"

int MS_PER_FRAME=1000/MAX_FPS;
SDL_Surface * surface;
sdl_image hi;

//Play around with these
double random_function(double random)
{
	return (safwat_pow(random,3)/(random*1000));
}
void color_function(int x,int y,double random)
{
	Uint8 red=cyclic_map(5);
	Uint8 green=cyclic_map(x*x/(100*random));
	Uint8 blue=cyclic_map(x*x/(10*random));


	draw_pixel(surface,x,y,red,green,blue);
}

///////////////////////////////////////////////////


Uint8 cyclic_map(Uint8 color)
{
	color=(int)safwat_abs(color)%256; //No negative colors allowed, limit to 255
	return cyclic[color];
}


int main(int argc, char *argv[])
{

    safwat_math_init_cyclic_map();
    prepare_sdl();
    hi=load_img("hi.png");
    //SDL_SetAlpha(hi,SDL_SRCALPHA,127);

    start_animating_until_stopped();
    SDL_FreeSurface(hi);
    SDL_Quit();
    return 0;
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

	double random=1;
	double old_random=0;


	while (1)
	{
		if (random!=old_random) //Draw only if something changed
		{
			old_random=random;
			draw_screen(random);
		}

		//random=random_function(random);
		random=random_function(current_time/10);

		if (handle_input()) return;

		//FPS limiter
		limit_fps(&current_time,&previous_time);
	}
}
void draw_screen(double random)
{
	int x,y;
	for (x=0; x<SCREEN_WIDTH; x++)
	{
	    for (y=0; y<SCREEN_HEIGHT; y++)
	    {
		color_function(x,y,random);
	    }
	}
	draw_image(surface,hi,30,30);
	SDL_Flip(surface);
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
