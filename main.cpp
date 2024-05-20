#include <cmath>
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

#include "constants.h"
#include "Point.h"
#include "Dataset.h"

int main()
{
  // Initialising SDL, a window and the renderer
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("New Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Setting some important variables up before the run loop
  SDL_Event event;
  bool running = true;
  Uint32 last_frame_time = SDL_GetTicks();
  const Uint32 frame_delay = 1000 / FRAMES_PER_SECOND;
  Uint32 frame_time, current_frame_time, delta_time;
  size_t i;

  Dataset d({1, 1.5, 2, 3}, {4, 4.5, 5, 6});

  while(running)
  {
    // Forcing fps and messing with frame time
    frame_time = SDL_GetTicks() - last_frame_time;
    if(frame_time < frame_delay) SDL_Delay(frame_delay - frame_time);
    current_frame_time = SDL_GetTicks();
    delta_time = current_frame_time - last_frame_time;

    // Checking for quit
    while(SDL_PollEvent(&event) != 0) {if(event.type == SDL_QUIT) running = false;}

    // Clearing the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Drawing data
    d.draw(renderer);

    // Updating screen
    SDL_RenderPresent(renderer);
    
    // Update frames
    last_frame_time = current_frame_time;
  }

  return 0;
}