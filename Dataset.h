#ifndef DATASET_H
#define DATASET_H

#include <vector>

#include "Point.h"

class Dataset
{
private:
  std::vector<Point> points;

public:
  Dataset(); // Default constructor
  Dataset(std::vector<double> x_in, std::vector<double> y_in); // Parameterised constructor

  Dataset(const Dataset& other); // Copy constructor
  Dataset(Dataset&& other) noexcept; // Move constructor

  Dataset& operator=(const Dataset& other); // Copy assignment
  Dataset& operator=(Dataset&& other) noexcept; // Move assignment

  ~Dataset() {}; // Destructor

  void print() const;
};

#endif