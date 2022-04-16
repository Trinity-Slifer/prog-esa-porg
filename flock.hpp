#ifndef FLOCK_HPP
#define FLOCK_HPP

#include <cmath>
#include <iostream>
#include <vector>

#include "boids.hpp"

class Flock {
 private:
  std::vector<Boid> b_flock;
  Rules b_rules;

 public:
  Flock(Rules const& rules) : b_rules{rules} {}
  void pushback(Boid const& pps) {
    b_flock.push_back(pps);
  }  // Definizione del pushback.
  int size() const { return b_flock.size(); }
  std::vector<Boid> copySEP = b_flock;
  std::vector<Boid> copyALI = b_flock;
  std::vector<Boid> copyCOH = b_flock;

  void evolve(double delta_t) {
    std::vector<Boid> copy = b_flock;  // creazione di una copia di b_flock
    // Si somma ogni singola veocitá data dalle regole alla velocitá
    // dell'i-esimo boid.
    for (size_t i = 0; i < b_flock.size(); i++) {
      copySEP = sep(b_flock, b_rules);
      copy[i].vel() += copySEP[i].vel();
      copyALI = ali(b_flock, b_rules);
      copy[i].vel() += copyALI[i].vel();
      copyCOH = coh(b_flock, b_rules);
      copy[i].vel() += copyALI[i].vel();
      copy[i].pos() = copy[i].pos() + copy[i].vel() * delta_t;
    }
    b_flock = copy;
  }
  std::vector<Boid> const& state() const { return b_flock; }

  Boid getBoid(int i) { return b_flock[i]; }

  Bvec CoMass(Flock b_flock) {
    Bvec CoMass = null;
    for (int i = 0; i < b_flock.size(); i++) {
      CoMass += getBoid(i).pos();
    }
    CoMass = CoMass / b_flock.size();
    return CoMass;
  }
};

#endif