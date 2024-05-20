#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
const int FRAMES_PER_SECOND = 60;
const int POINT_SIZE = 6;
const int GRAPH_LEFT = 100;
const int GRAPH_RIGHT = SCREEN_WIDTH - 100;
const int GRAPH_WIDTH = GRAPH_RIGHT - GRAPH_LEFT;
const int GRAPH_TOP = 200;
const int GRAPH_BOTTOM = SCREEN_HEIGHT - 200;
const int GRAPH_HEIGHT = GRAPH_BOTTOM - GRAPH_TOP;

void draw_square(SDL_Renderer* renderer, const int& x, const int& y, const int& size);
void draw_vertical_line(SDL_Renderer* renderer, const int& x, const int& y, const int& height, const int& width);
void draw_horizontal_line(SDL_Renderer* renderer, const int& x, const int& y, const int& height, const int& width);

#endif