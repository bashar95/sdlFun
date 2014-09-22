#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
typedef SDL_Surface * sdl_image;
void draw_pixel(SDL_Surface * surface, int x, int y, Uint8 r, Uint8 g, Uint8 b);
sdl_image load_img(const char * path);
void  draw_image(SDL_Surface *surface, sdl_image image,int x,int y);

