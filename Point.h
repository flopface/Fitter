struct Point
{
  int x;
  int y;

  Point();
  Point(int x_in, int y_in);
  ~Point();

  Point(const Point& other); // Copy constructor
  Point(Point&& other) noexcept; // Move constructor

  Point& operator=(const Point& other); // Copy assignment
  Point& operator=(Point&& other) noexcept; // Move assignment
};