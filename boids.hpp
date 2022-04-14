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
  // nt size() const { return }
};

float d{};
float ds_;
double s;
Bvec null{0., 0., 0.};
std::vector<Boid> sep(std::vector<Boid>& Boids) {
  std::vector<Boid> copysep = Boids;
  for (size_t i; i < Boids.size(); i++) {
    copysep[i].vel() = null;
    for (size_t j; j < Boids.size(); j++) {
      double ds = magn(Boids[i].pos() - Boids[j].pos());
      if ((ds > 0) && (ds < d)) {
        if (ds < ds_) {
          copysep[i].vel() += (-((Boids[i].pos() - Boids[j].pos()) * s));
        }
      }
    }
  }
  return copysep;
}
double a;
std::vector<Boid> ali(std::vector<Boid>& Boids) {
  std::vector<Boid> copyali = Boids;
  for (size_t i; i < Boids.size(); i++) {
    Bvec velali = null;
    int count;
    for (size_t j; j < Boids.size(); j++) {
      double ds = magn(Boids[i].pos() - Boids[j].pos());
      if ((ds < d) && (ds > 0)) {
        velali += (Boids[j].vel() - Boids[i].vel());
        count++;
      }
    }
    copyali[i].vel() = (velali / count) * a;
  }
  return copyali;
}

double c;
std::vector<Boid> coh(std::vector<Boid>& Boids) {
  std::vector<Boid> copycoh = Boids;
  for (size_t i; i < Boids.size(); i++) {
    Bvec com = null;
    copycoh[i].vel() = null;
    int count;
    for (size_t j; j < Boids.size(); j++) {
      double ds = magn(Boids[i].pos() - Boids[j].pos());
      if ((ds > 0) && (ds < d)) {
        com = Boids[j].pos();
        count++;
      }
    }
    com = com / count;
    copycoh[i].vel() = (com - Boids[i].pos()) * c;
  }
  return copycoh;
}
#endif