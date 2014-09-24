#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <unistd.h>
typedef SDL_Surface * sdl_image;

//Init
void SDLH_StartSDL(int w,int h,int fps,const char * title);
void SDLH_QuitSDL();

//FPS limiter
void SDLH_LimitFps();

//Draw
void SDLH_DrawStart();
void SDLH_ClearScreen();
void SDLH_DrawEnd();

//Pixel
void SDLH_DrawPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);


//Image
sdl_image SDLH_LoadImage(const char * path);
void SDLH_DrawImage(sdl_image image,int x,int y);

