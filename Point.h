#ifndef POINT_H
#define POINT_H

struct Point
{
  double x;
  double y;

  Point();
  Point(double x_in, double y_in);
  ~Point();

  Point(const Point& other); // Copy constructor
  Point(Point&& other) noexcept; // Move constructor

  Point& operator=(const Point& other); // Copy assignment
  Point& operator=(Point&& other) noexcept; // Move assignment
};

#endif