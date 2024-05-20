#include "functions.h"
#include <SDL2/SDL.h>

void draw_square(SDL_Renderer* renderer, const int& x, const int& y, const int& size)
{
  SDL_Rect square = {x-size, y-size, size+1, size+1};
  SDL_RenderFillRect(renderer, &square);
}

void draw_vertical_line(SDL_Renderer* renderer, const int& x, const int& y, const int& height, const int& width)
{
  SDL_Rect line = {x-width, y-width, width+1, height+1};
  SDL_RenderFillRect(renderer, &line);
}

void draw_horizontal_line(SDL_Renderer* renderer, const int& x, const int& y, const int& height, const int& width)
{
  SDL_Rect line = {x-height, y-height, width+1, height+1};
  SDL_RenderFillRect(renderer, &line);
}