#include <vector>
#include <iostream>

#include "Dataset.h"
#include "Point.h"

Dataset::Dataset() {} // Default constructor

Dataset::Dataset(std::vector<double> x_in, std::vector<double> y_in) // Parameterised constructor
{
  if(x_in.size() > y_in.size()) return;
  for(size_t i = 0; i != x_in.size(); i++) points.emplace_back(x_in[i], y_in[i]);
}

Dataset::Dataset(const Dataset& other) // Copy constructor
{
  points = other.points;
}

Dataset::Dataset(Dataset&& other) noexcept // Move constructor
{
  points = std::move(other.points);
}

Dataset& Dataset::operator=(const Dataset& other) // Copy assignment
{
  if(this != &other)
  {
    points = other.points;
  }
  return *this;
}

Dataset& Dataset::operator=(Dataset&& other) noexcept // Move assignment
{
  if(this != &other)
  {
    points = std::move(other.points);
  }
  return *this;
}

void Dataset::print() const
{
  std::cout<<"___Data________\n";
  for(size_t i = 0; i != points.size(); i++) std::cout<<i<<" : ["<<points[i].x<<", "<<points[i].y<<"]\n";
  for(size_t i = 0; i != 15; i++)std::cout<<"\u203e";
  std::cout<<std::endl;
}
