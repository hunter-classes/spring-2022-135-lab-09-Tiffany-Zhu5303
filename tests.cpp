#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "coord3d.h"
#include "3d-space.h"

TEST_CASE("Length of vectors"){
  Coord3D points = {4, 1, 8};
  CHECK(length(&points) == 9);

  points = {15, 4, 5};
  //doctest::Approx() -> approximate floating number .epsilon() -< allow a percentage of error
  CHECK(length(&points) == doctest::Approx(16.3095064303).epsilon(0.02));

  points = {1.5, 4.5, 1.6};
  CHECK(length(&points) == doctest::Approx(5.00599640431).epsilon(0.02));

  points = {1, 4.0/18.0, 11.0/15.0};
  CHECK(length(&points) == doctest::Approx(1.25982558072).epsilon(0.02));
}

TEST_CASE("Farthest vector from origin"){
  Coord3D secondVector = {1, 2, 3};
  Coord3D firstVector = {15, 4, 5};

  CHECK(fartherFromOrigin(&secondVector, &firstVector) == &firstVector);

  firstVector = {7, 8, 14};
  secondVector = {6.33, 7.33, 8.14};

  CHECK(fartherFromOrigin(&secondVector, &firstVector) == &firstVector);

  firstVector = {21, 1, 1};
  secondVector = {11, 15, 0};

  CHECK(fartherFromOrigin(&secondVector, &firstVector) == &firstVector);
}

TEST_CASE("Move coordinates"){
  Coord3D pos = {12, 67, 17.6};
  Coord3D vel = {1, -4, -5};

  move(&pos, &vel, 6);
  CHECK(pos.x == 18);
  CHECK(pos.y == 43);
  CHECK(pos.z == doctest::Approx(-12.4).epsilon(0.02));

  pos = {3, 4, 5};
  vel = {5, 12, 13};

  move(&pos, &vel, 5.6);
  CHECK(pos.x == 31);
  CHECK(pos.y == doctest::Approx(71.2).epsilon(0.02));
  CHECK(pos.z == doctest::Approx(77.8).epsilon(0.02));
}

TEST_CASE("Make and create coordinates"){
  double x = 12, y = 4, z = 4;
  Coord3D *ppos = createCoord3D(x, y, z);
  
  CHECK(ppos->x == 12);
  CHECK(ppos->y == 4);
  CHECK(ppos->z == 4);
  
  x = 4, y = 2; z = 7;
  Coord3D *pvel = createCoord3D(x, y, z);

  CHECK(pvel->x == 4);
  CHECK(pvel->y == 2);
  CHECK(pvel->z == 7);

  move(ppos, pvel, 2);

  CHECK(ppos->x == 20);
  CHECK(ppos->y == 8);
  CHECK(ppos->z == 18);

  deleteCoord3D(ppos);
  deleteCoord3D(pvel);
}
