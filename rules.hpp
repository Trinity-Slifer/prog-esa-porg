#ifndef RULES_HPP
#define RULES_HPP

#include <cmath>
#include <iostream>
#include <vector>

#include "boids.hpp"

class Rules {
 private:
  int n_{};
  double a_{};
  double s_{};
  double c_{};
  double d_{};

 public:
  Rules(int n, double a, double s, double c, double d)
      : n_{n}, a_{a}, s_{s}, c_{c}, d_{d} {}
  Bvec sep;
  Bvec all;
  double s;

  double operator()(Boids const& p1, Boids const& p2) {
    if (norm(p1.pos() - p2.pos()) < d_) {
      Bvec separation = - ((p1.pos() - p2.pos()) * s));
    }
  }
};

#endif