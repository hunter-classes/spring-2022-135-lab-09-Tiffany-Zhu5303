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
