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

  Coord3D * ans = fartherFromOrigin(&coords, &secondCoords);
  std::cout << "\nThe farthest one from the origin is " << ans << std::endl;

  std::cout << "\n----------------Task C----------------\n" << std::endl;
  Coord3D pos = {0, 0, 100.0};
  Coord3D vel = {1, -5, 0.2};

  move(&pos, &vel, 2.0);
  std::cout << "These are the new positions: " << pos.x << " " << pos.y << " " << pos.z << std::endl;

  std::cout << "\n----------------Task E----------------\n" << std::endl;
  double x = 10, y = 20, z = 30;
  Coord3D *ppos = createCoord3D(x, y, z);

  x = 0; y = 6; z = 1.0;
  Coord3D *pvel = createCoord3D(x, y, z);

  move(ppos, pvel, 3);

  std::cout << "Coordinates after 3 seconds: " << ppos->x << " " << ppos->y << " " << ppos->z << std::endl;

  deleteCoord3D(ppos);
  deleteCoord3D(pvel);
  
  return 0;
}
