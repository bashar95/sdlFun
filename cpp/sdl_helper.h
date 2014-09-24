#pragma once
class cSdlh;

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <unistd.h>
typedef SDL_Surface * SdlhImage;

class cSdlh
{
	
public:

//Initialize
static void StartSDL(int w, int h, int fps, const char * title, bool fullscreen);
static void QuitSDL();

//FPS limiter
static void LimitFps();

//Draw control
static void DrawStart();
static void ClearScreen();
static void DrawEnd();

//Pixel
static void DrawPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);

//Image
SdlhImage LoadImage(const char * path);
static void DrawImage(SdlhImage image, int x, int y);





private:

static SDL_Surface * s_surface;
static Uint32 s_currentTime;
static Uint32 s_previousTime;

static int s_screenWidth;
static int s_screenHeight;
static int s_maxFps;
static int s_msPerFrame;

};


