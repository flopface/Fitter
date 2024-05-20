#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <iostream>
#include <SDL2/SDL.h>

#include "Point.h"

class Dataset
{
private:
  std::vector<Point> points;
  double x_min;
  double x_max;
  double x_range;
  double y_min;
  double y_max;
  double y_range;

public:
  Dataset(); // Default constructor
  Dataset(std::string file_name, size_t skip_header = 1); // File extractor
  Dataset(std::vector<double> x_in, std::vector<double> y_in); // Parameterised constructor

  Dataset(const Dataset& other); // Copy constructor
  Dataset(Dataset&& other) noexcept; // Move constructor

  Dataset& operator=(const Dataset& other); // Copy assignment
  Dataset& operator=(Dataset&& other) noexcept; // Move assignment

  ~Dataset() {}; // Destructor

  void print() const;
  void draw(SDL_Renderer* renderer);

};

#endif