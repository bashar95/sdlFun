//apt-get install libsdl-image1.2-dev libsdl-dev
#include "sdl_helper.h"
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define MAX_FPS 30


int HandleInput();
void GameLoop();
void AnimateStuff();
///////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    SDLH_StartSDL(SCREEN_WIDTH,SCREEN_HEIGHT,MAX_FPS,"Minimal test");
    GameLoop();
    SDLH_QuitSDL();
    return 0;
}

void GameLoop()
{
	while (1)
	{
		AnimateStuff();
		if (HandleInput()) return;
		SDLH_LimitFps();
	}
}

int randomNumForFun=0;
int deltaNumForFun=1;
void AnimateStuff()
{
	SDLH_DrawStart();
	//SDLH_ClearScreen(); //Something interesting will happen if you comment this ;)
	int x,y;
	for (x=randomNumForFun; x<SCREEN_WIDTH; x++)
	{
	    for (y=0; y<SCREEN_HEIGHT; y++)
	    {
		SDLH_DrawPixel(x,y,x%255,y%255,(x+y+randomNumForFun)%255);
	    }
	}
	if (randomNumForFun>=SCREEN_WIDTH || randomNumForFun<0) deltaNumForFun*=-1;
	randomNumForFun+=deltaNumForFun;
	SDLH_DrawEnd();
}

int HandleInput()
{
	SDL_Event event;
	while ( SDL_PollEvent(&event) )
	{
	    switch (event.type)
	    {
			case SDL_MOUSEMOTION:
				//random=random_function(event.motion.x,event.motion.y);
			break;
			
			
			//case SDL_MOUSEMOTION:
			//case SDL_MOUSEBUTTONDOWN:
				//event.button.x , event.button.y
			//case SDL_KEYUP
			case SDL_KEYDOWN:
				//if (event.key.keysym.sym==SDLK_LEFT) blahblah
				//if (event.key.keysym.sym==SDLK_LEFT) blahblah
				//Works: SDLK_F10, SDLK_HOME, SDLk_ENTER, SDLK_w, SDLK_s, SDLK_1
			case SDL_QUIT:
				return 1;
	    }
	}
}

