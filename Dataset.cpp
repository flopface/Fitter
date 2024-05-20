#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SDL2/SDL.h>

#include "functions.h"
#include "Dataset.h"
#include "Point.h"

void Dataset::draw(SDL_Renderer* renderer)
{
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

  for(std::vector<Point>::iterator it = points.begin(); it != points.end(); it++)
  {
    draw_square(renderer, static_cast<int>(GRAPH_LEFT + GRAPH_WIDTH*(it->x-x_min)/x_range), static_cast<int>(GRAPH_BOTTOM - GRAPH_HEIGHT*(it->y-y_min)/y_range), POINT_SIZE);
    //SDL_Rect squareRect = {static_cast<int>(GRAPH_LEFT + GRAPH_WIDTH*(it->x-x_min)/x_range), static_cast<int>(GRAPH_BOTTOM - GRAPH_HEIGHT*(it->y-y_min)/y_range), POINT_SIZE, -POINT_SIZE};
    //SDL_RenderFillRect(renderer, &squareRect);
  }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

Dataset::Dataset() {} // Default constructor

Dataset::Dataset(std::string file_name, size_t skip_header) // File extractor
{
  std::ifstream file{file_name};
  std::string line;
  double x_temp, y_temp;
  char blank;
  for(size_t i = 0; i != skip_header; i++) std::getline(file, line);
  std::getline(file, line);
  std::stringstream line_stream(line);
  line_stream>>x_temp>>blank>>y_temp;
  points.emplace_back(x_temp, y_temp);
  x_max  = x_temp;
  x_min = x_temp;
  y_max  = y_temp;
  y_min = y_temp;
  while(std::getline(file, line))
  {
    std::stringstream line_stream(line);
    line_stream>>x_temp>>blank>>y_temp;
    points.emplace_back(x_temp, y_temp);
    if(x_temp > x_max) x_max  = x_temp;
    else if(x_temp < x_min) x_min  = x_temp;
    if(y_temp > y_max) y_max  = y_temp;
    else if(y_temp < y_min) y_min  = y_temp;
  }
  x_range = x_max - x_min;
  y_range = y_max - y_min;
}

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
    if(x_in[i] > x_max) x_max  = x_in[i];
    else if(x_in[i] < x_min) x_min  = x_in[i];
    if(y_in[i] > y_max) y_max  = y_in[i];
    else if(y_in[i] < y_min) y_min  = y_in[i];
  }
  x_range = x_max - x_min;
  y_range = y_max - y_min;
}

void Dataset::print() const
{
  std::cout<<"___Data___________________________________________\n";
  for(size_t i = 0; i != points.size(); i++) std::cout<<i<<" : ["<<points[i].x<<", "<<points[i].y<<"]\n";
  std::cout<<"length = "<<points.size()<<"\n";
  std::cout<<"x_min = "<<x_min<<", x_max = "<<x_max<<", y_min = "<<y_min<<", y_max = "<<y_max<<"\n";
  std::cout<<"x_range = "<<x_range<<", y_range = "<<y_range<<"\n";
  for(size_t i = 0; i != 50; i++)std::cout<<"\u203e";
  std::cout<<std::endl;
}

Dataset::Dataset(const Dataset& other) // Copy constructor
{
  points = other.points;
  x_min = other.x_min;
  x_max = other.x_max;
  x_range = other.x_range;
  y_min = other.y_min;
  y_max = other.y_max;
  y_range = other.y_range;
}

Dataset::Dataset(Dataset&& other) noexcept // Move constructor
{
  points = std::move(other.points);
  x_min = other.x_min;
  x_max = other.x_max;
  x_range = other.x_range;
  y_min = other.y_min;
  y_max = other.y_max;
  y_range = other.y_range;
  other.x_min = 0;
  other.x_max = 0;
  other.x_range = 0;
  other.y_min = 0;
  other.y_max = 0;
  other.y_range = 0;
}

Dataset& Dataset::operator=(const Dataset& other) // Copy assignment
{
  if(this != &other)
  {
    points = other.points;
    x_min = other.x_min;
    x_max = other.x_max;
    x_range = other.x_range;
    y_min = other.y_min;
    y_max = other.y_max;
    y_range = other.y_range;
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
    x_range = other.x_range;
    y_min = other.y_min;
    y_max = other.y_max;
    y_range = other.y_range;
    other.x_min = 0;
    other.x_max = 0;
    other.x_range = 0;
    other.y_min = 0;
    other.y_max = 0;
    other.y_range = 0;
  }
  return *this;
}
