#ifndef BOIDS_HPP
#define BOIDS_HPP

#include <cmath>
#include <iostream>
#include <vector>

#include "vectors.hpp"

class Boid {
 private:
  Bvec b_pos;
  Bvec b_vel;

 public:
  Boid(Bvec pos, Bvec vel) : b_pos{pos}, b_vel{vel} {}
  Bvec pos() const { return b_pos; };
  Bvec vel() const { return b_vel; };
  Bvec locate = pos();
  // nt size() const { return }
};

float d{};
Bvec null{0., 0., 0.};
std::vector<Boid> sep(std::vector<Boid>& Boids) {
  double s;
  std::vector<Boid> copy = Boids;
  for (int i; i < Boids.size(); i++) {
    copy[i].vel() = null;
    for (int j; j < Boids.size(); j++) {
      float ds = magn(Boids[i].pos() - Boids[j].pos());
      if ((ds > 0) && (ds < d)) {
        copy[i].vel() += (-((Boids[i].pos() - Boids[j].pos()) * s));
      }
    }
  }
  return copy;
}

#endif