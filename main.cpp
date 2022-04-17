#include <iostream>
#include <vector>

#include "flock.hpp"

int main() {
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
  std::vector<Boid> res0 = flock.state();
  print(res0[0].vel());
}