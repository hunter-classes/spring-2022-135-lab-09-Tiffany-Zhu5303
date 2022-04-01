#include <iostream>
#include "funcs.h"
#include "3d-space.h"


Coord3D* fartherFromOrigin(Coord3D *p1, Coord3D *p2){
  if(length(p1) > length(p2)){
    
    return p1;
    
  }else{
    
    return p2;
  }
}
