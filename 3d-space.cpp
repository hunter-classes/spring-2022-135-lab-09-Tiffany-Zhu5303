#include <iostream>
#include <math.h>
#include "3d-space.h"
#include "coord3d.h"

double length(Coord3D *p){

  p->x = pow(p->x, 2);
  p->y = pow(p->y, 2);
  p->z = pow(p->z, 2);

  double vectorLength = pow(p->x + p->y + p->z, 0.5);

  return vectorLength;
}
