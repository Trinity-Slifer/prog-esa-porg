#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "flock.hpp"

TEST_CASE("TESTING VECTORS") {
  SUBCASE("testing +") {
    Bvec v1{1., 2., 1.};
    Bvec v2{2., 3., 1.};
    Bvec v3{4., 3., 2.};
    Bvec res1{3., 5., 2.};
    Bvec res2{6., 6., 3.};
    Bvec res3{5., 5., 3.};
    CHECK(v1 + v2 == res1);
    CHECK(v2 + v3 == res2);
    CHECK(v1 + v3 == res3);
  }
  SUBCASE("testing -") {
    Bvec v1{1., 2., 1.};
    Bvec v2{2., 3., 1.};
    Bvec v3{4., 3., 2.};
    Bvec res1{-1., -1., 0.};
    Bvec res2{-2., 0., -1.};
    Bvec res3{-3., -1., -1.};
    CHECK(v1 - v2 == res1);
    CHECK(v2 - v3 == res2);
    CHECK(v1 - v3 == res3);
  }
  SUBCASE("testing *") {
    Bvec v1{1., 2., 1.};
    Bvec v2{2., 3., 1.};
    Bvec v3{4., 3., 2.};
    Bvec res1{2., 4., 2.};
    Bvec res3{3., 6., 3.};
    CHECK(v1 * 2. == res1);
    CHECK(v2 * 1. == v2);
    CHECK(v1 * 3. == res3);
  }
  SUBCASE("testing *") {
    Bvec v1{1., 2., 1.};
    Bvec v2{2., 3., 1.};
    Bvec v3{4., 3., 2.};
    CHECK(v1 * v2 == 9.);
    CHECK(v2 * v3 == 19.);
    CHECK(v1 * v3 == 12.);
  }
  SUBCASE("testing /") {
    Bvec v1{1., 2., 1.};
    Bvec v2{2., 3., 1.};
    Bvec v3{4., 3., 2.};
    Bvec res1{1., 1.5, 0.5};
    Bvec res2{-4., -3., -2.};
    CHECK(v1 / 1. == v1);
    CHECK(v2 / 2. == res1);
    CHECK(v3 / -1. == res2);
  }
  SUBCASE("testing magn") {
    Bvec v1{1., 2., 1.};
    Bvec v2{2., 3., 1.};
    Bvec v3{4., 0., 0.};
    CHECK(magn(v2) == sqrt(14.));
    CHECK(magn(v3) == 4.);
    CHECK(magn(v1) == sqrt(6.));
  }

  SUBCASE("testing +=") {
    Bvec v1{1., 2., 1.};
    Bvec v2{2., 3., 1.};
    Bvec v3{4., 3., 2.};
    Bvec res1{3., 5., 2.};
    Bvec res2{6., 6., 3.};
    Bvec res3{5., 5., 3.};
    CHECK(v1 += v2 == res1);
    CHECK(v2 += v3 == res2);
    CHECK(v1 += v3 == res3);
  }
}

TEST_CASE("TESTING FLOCKS") {
  Bvec P1{1., 0., 0.};
  Bvec P2{0., 0., 0.};
  Bvec V1{1., 1., 1.};
  Bvec V2{1., 1., 0.};
  Boid b1{P1, V1};
  Boid b2{P2, V2};
  std::vector<Boid> Boids{b1, b2};
  Rules r1(2., 2., 1., 1., 1.);
  Flock flock{Boids, r1};
  flock.evolve(1.);
  SUBCASE("Separation") {
    std::vector<Boid> res = sep(Boids, r1);
    Bvec ciao = res[0].vel();
    Bvec k = {1., 0., 0.};
    CHECK(ciao == k);
  }
  SUBCASE("Testing with 2 Boids") {
    std::vector<Boid> res0 = flock.state();
    Bvec res = (res0[0].vel());
    Bvec res1 = {1., 1., 0};
    CHECK(res == res1);
  }
}
