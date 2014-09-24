//apt-get install libsdl-image1.2-dev libsdl-dev
#include "../cpp/sdlfun.h"
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define MAX_FPS 10


int HandleInput();
void GameLoop();
void DrawLine();
///////////////////////////////////////////////////

int main()
{
    cSdlh::StartSDL(SCREEN_WIDTH,SCREEN_HEIGHT,MAX_FPS,"Minimal test",false);
    GameLoop();
    cSdlh::QuitSDL();
    return 0;
}

void GameLoop()
{
	while (1)
	{
		if (HandleInput()) return;
		cSdlh::LimitFps();
	}
}

void DrawLine(int startX, int startY, int endX, int endY)
{
	//Tan undefined here
	cSdlh::DrawStart();
	//cSdlh::ClearScreen(); //More fun without it
	if (startX==endX)
	{
		int delta;
		int y;
		if (endY>startY) delta=1;
		else delta=-1;
		
		for (y=startY; y==endY; y+=delta)
		{
			cSdlh::DrawPixel(startX,y,254, 0, 0);
		}
		return;
	}
	
	int density=1;
	
	
	int xdir,ydir;
	xdir=-1;
	ydir=-1;
	if (endX>startX) xdir=1;
	if (endY>startY) ydir=1;
	
	double x, y;
	double tan = (endY-startY)/(double)(endX-startX );
	if (tan<0) tan*=-1;
	double d=1 / (1+tan);
	
		for (x=startX,y=startY; (endX-x)*xdir>0;)
		{
			cSdlh::DrawPixel((int)x,(int)y, 254, 0, 0);
			x+=xdir*d*density;
			y+=ydir*tan*d*density;
		}
	cSdlh::DrawEnd();
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
			case SDL_MOUSEBUTTONDOWN:
				DrawLine(100, 400, event.button.x, event.button.y);
			break;


			//case SDL_KEYUP
			case SDL_KEYDOWN:
				//if (event.key.keystartym.startym==SDLK_LEFT) blahblah
				//if (event.key.keystartym.startym==SDLK_LEFT) blahblah
				//Works: SDLK_F10, SDLK_HOME, SDLk_ENTER, SDLK_w, SDLK_s, SDLK_1
			case SDL_QUIT:
				return 1;
	    }
	}
}

