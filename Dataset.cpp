#include <vector>
#include <iostream>
#include <SDL2/SDL.h>

#include "Dataset.h"
#include "Point.h"

void Dataset::draw(SDL_Renderer* renderer) const
{
  /*SDL_Rect squareRect = {static_cast<int>(x_position/800000000+SCREEN_WIDTH/2-size/2), static_cast<int>(-y_position/800000000+SCREEN_WIDTH/2-size/2), size, size};
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_RenderFillRect(renderer, &squareRect);*/
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

Dataset::Dataset() {} // Default constructor

Dataset::Dataset(std::vector<double> x_in, std::vector<double> y_in) // Parameterised constructor
{
  if(x_in.size() != y_in.size() || x_in.empty()) return;
  x_max  = x_in[0];
  x_min = x_in[0];
  y_max  = y_in[0];
  y_min = y_in[0];
  for(size_t i = 0; i != x_in.size(); i++) 
  {
    points.emplace_back(x_in[i], y_in[i]);
    if(x_in[i] > x_max ) x_max  = x_in[i];
    else if(x_in[i] < x_min) x_min  = x_in[i];
    if(y_in[i] > y_max ) y_max  = y_in[i];
    else if(y_in[i] < y_min) y_min  = y_in[i];
  }
}

void Dataset::print() const
{
  std::cout<<"___Data___________________________________________\n";
  std::cout<<"length = "<<points.size();
  std::cout<<"\nx_min = "<<x_min<<", x_max = "<<x_max<<", y_min = "<<y_min<<", y_max = "<<y_max<<"\n\n";
  for(size_t i = 0; i != points.size(); i++) std::cout<<i<<" : ["<<points[i].x<<", "<<points[i].y<<"]\n";
  for(size_t i = 0; i != 50; i++)std::cout<<"\u203e";
  std::cout<<std::endl;
}

Dataset::Dataset(const Dataset& other) // Copy constructor
{
  points = other.points;
  x_min = other.x_min;
  x_max = other.x_max;
  y_min = other.y_min;
  y_max = other.y_max;
}

Dataset::Dataset(Dataset&& other) noexcept // Move constructor
{
  points = std::move(other.points);
  x_min = other.x_min;
  x_max = other.x_max;
  y_min = other.y_min;
  y_max = other.y_max;
  other.x_min = 0;
  other.x_max = 0;
  other.y_min = 0;
  other.y_max = 0;
}

Dataset& Dataset::operator=(const Dataset& other) // Copy assignment
{
  if(this != &other)
  {
    points = other.points;
    x_min = other.x_min;
    x_max = other.x_max;
    y_min = other.y_min;
    y_max = other.y_max;
  }
  return *this;
}

Dataset& Dataset::operator=(Dataset&& other) noexcept // Move assignment
{
  if(this != &other)
  {
    points = std::move(other.points);
    x_min = other.x_min;
    x_max = other.x_max;
    y_min = other.y_min;
    y_max = other.y_max;
    other.x_min = 0;
    other.x_max = 0;
    other.y_min = 0;
    other.y_max = 0;
  }
  return *this;
}
