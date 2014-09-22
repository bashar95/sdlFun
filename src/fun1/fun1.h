#include "SDL/SDL.h"
#include "safwat_math.h"
#include "sdl_helper.h"
#include <time.h>

double random_function(double random);
void color_function(int x,int y,double random);
void prepare_sdl();
void start_animating_until_stopped();
void draw_screen(double random);
int handle_input();
void limit_fps(Uint32 * current_time,Uint32 * previous_time);

Uint8 cyclic_map(Uint8 color);
