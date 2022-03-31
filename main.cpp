#include <iostream>

#include "coord3d.h"
#include "funcs.h"
#include "3d-space.h"

int main()
{
  Coord3D coords = {10, 20, 30};
  
  std::cout << "----------------Task A----------------\n" << std::endl;
  std::cout << "For the coordinates " << coords.x << ", " << coords.y << ", " << coords.z << std::endl;
  std::cout << "The length of these coordinates is " << length(&coords) << std::endl;

  std::cout << "\n----------------Task B----------------\n" << std::endl;
  Coord3D secondCoords = {-20, 21, -22};

  std::cout << "The address of P: " << &coords << std::endl;
  std::cout << "The address of Q: " << &secondCoords << std::endl;
  
  return 0;
}
