sdlFun
======
In a sentence: sdlFun is an extremely simple way to draw 2d pixels / images on the screen.

SDL is a cross-platform graphics library. This repository contains an extremely minimal SDL wrapper written in both C andC++, which makes 2d screen drawing as easy as it could get. It is not intended for making anything fancy. sdlFun is suitable for games with basic graphics requirements such as pixel art games. It is also a great tool for learning 2d graphics.

Features
======
* Draw pixels directly on screen.
* Draw images on screen (.bmp , .png) 
* FPS limiter

Also see the to-do list below.

Demo
======
Here is a basic demo. A more advanced demo can be found at `c/minimal.c` or `cpp/minimal.cpp`.

```
#include "sdl_helper.h"
int main()
{
	SDLH_StartSDL(300,300,30,"HEllo pixel"); //(Width, Height, Max FPS, Window Title)

	SDLH_DrawStart(); //Only call drawing stuff between DrawStart and DrawEnd
	SDLH_ClearScreen(); //Clear the screen (Paint it black).

	//This simply draws a red pixel.
	SDLH_DrawPixel(5,5,255,0,0); //(X, Y, Red, Green, Blue)

	sdl_image coolimage = SDLH_LoadImage("myCoolImage.png");  //Loads image from disk
	SDLH_DrawImage(coolimage, 20, 20); //Draws the loaded image on screen

	SDLH_DrawEnd();
	SDLH_QuitSDL();
	return 0;
}
```

Getting and using sdlFun
======
sdlFun depends on some libraries. The following sections explain how to install and use sdlFun.

Windows
======
Something here soon.
I don't have ready-to-use instructions, sorry. SDL is cross platform, therefore sdlFun will work fine on Windows once the dependencies are installed. The dependencies are: `sdl-image` , `sdl`.

GNU/Linux Debian:
======
```
#Get all the needed dependencies
apt-get install gcc git libsdl-image1.2-dev libsdl-dev

#Get sdlFun
git clone https://github.com/wiseoldman95/sdlFun.git 

#Compile the demo:
cd sdlFun/c OR cd sdlFun/cpp 
make
#If all works well, you should get a new file `sdlfun.out`

#Run it:
/.sdlfun.out

#Feel free to play around with minimal.c and then execute `make` again.
#Have fun!
```

To-do list
======
* Function to unload images
* Delta timing
* Test the Debian instructions on Ubuntu, Mint, etc.
* Sound and networking wrappers


