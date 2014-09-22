#include "sdl_helper.h"
void draw_pixel(SDL_Surface * surface, int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
    Uint8 * pixel = (Uint8*)surface->pixels;
    pixel += (y * surface->pitch) + (x * (sizeof(Uint8) * 3));
    pixel[2] = r;
    pixel[1] = g;
    pixel[0] = b;
}
sdl_image load_img(const char * path)
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
void draw_image(SDL_Surface *surface, SDL_Surface *  image,int x,int y)
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
