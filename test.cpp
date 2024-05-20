#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>

int main()
{
  std::ifstream file{"data/1020.csv"};
  int i = 0;
  std::string line;
  char blank;
  double x, y;
  while(i < 10)
  {
    std::getline(file, line);
    std::stringstream line_stream(line);
    line_stream>>x>>blank>>y;
    std::cout<<x<<" "<<y<<std::endl;
    i++;
  }

  return 0;
}