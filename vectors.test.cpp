#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "vectors.hpp"

#include "doctest.h"

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
}