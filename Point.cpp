#include "Point.h"

Point::Point() : x{0}, y{0} {}

Point::Point(int x_in, int y_in) : x{x_in}, y{y_in} {}

Point::~Point() {}

Point::Point(const Point& other) // Copy constructor
{
  x = other.x;
  y = other.y;
}

Point::Point(Point&& other) noexcept // Move constructor
{
  x = other.x;
  y = other.y;
  other.x = 0;
  other.y = 0;
}

Point& Point::operator=(const Point& other) // Copy assignment
{
  if(this != &other)
  {
    x = other.x;
    y = other.y;
  }
  return *this;
}

Point& Point::operator=(Point&& other) noexcept // Move assignment
{
  if(this != &other)
  {
    x = other.x;
    y = other.y;
    other.x = 0;
    other.y = 0;
  }
  return *this;
}
