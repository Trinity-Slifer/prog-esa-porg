#ifndef BOIDS_HPP
#define BOIDS_HPP

#include <cmath>
#include <iostream>
#include <vector>

#include "vectors.hpp"

class Boid {  // Classe Boid formata da due vettori, uno posizione e uno
              // velocitá.
 private:
  Bvec b_pos;
  Bvec b_vel;

 public:
  Boid(Bvec pos, Bvec vel) : b_pos{pos}, b_vel{vel} {}
  Bvec pos() const { return b_pos; };
  Bvec vel() const { return b_vel; };
  // nt size() const { return }
};

class Rules {  // Classe delle tre regole che definiscono il comportamento dei
               // vari Boids.
 private:
  double d_;
  double dss_;
  double s_;
  double a_;
  double c_;

 public:
  Rules(double d, double dss, double s, double a, double c)
      : d_{d}, dss_{dss}, s_{s}, a_{a}, c_{c} {}
  double d() const { return d_; }
  double dss() const { return dss_; }
  double s() const { return s_; }
  double a() const { return a_; }
  double c() const { return c_; }
};

Bvec null{0., 0., 0.};
std::vector<Boid> sep(std::vector<Boid>& Boids,
                      Rules const& rule) {  // Regola di separazione.
  std::vector<Boid> copysep = Boids;
  for (size_t i; i < Boids.size(); i++) {  // Per ogni Boid.
    // Si azzera la velocitá e la posizione copia relativa all'i-esimo Boid.
    copysep[i].vel() = null;
    copysep[i].pos() = null;
    for (size_t j; j < Boids.size(); j++) {  // Per ogni Boid.
      double ds = magn(Boids[i].pos() - Boids[j].pos());
      // Presi solo i Boid vicini diversi dal Boid stesso
      if ((ds > 0) && (ds < rule.d())) {
        // Se il Boid é abbastanza vicino da essere affetto
        // dalla regola di separazione.
        if (ds < rule.dss()) {
          // Regola di separazione.
          copysep[i].vel() += (-((Boids[i].pos() - Boids[j].pos()) * rule.s()));
        }
      }
    }
  }
  return copysep;
}
// Regola di allineamento.
std::vector<Boid> ali(std::vector<Boid>& Boids, Rules const& rule) {
  std::vector<Boid> copyali = Boids;
  for (size_t i; i < Boids.size(); i++) {  // Per ogni Boid.
    // Dichiarazione di un vettore velocitá utile per definire la velocitá
    // data dall'allineamento dei Boid vicini, é una sommatoria.
    Bvec velali = null;
    int count;  // contatore del numero di Boids vicini.
    // Si azzera la velocitá e la posizione copia relativa all'i-esimo Boid.
    copyali[i].vel() = null;
    copyali[i].pos() = null;
    for (size_t j; j < Boids.size(); j++) {  // Per ogni Boid.
      // Si calcola la distanza tra due Boid.
      double ds = magn(Boids[i].pos() - Boids[j].pos());
      // Presi solo i Boid vicini diversi dal Boid stesso
      if ((ds < rule.d()) && (ds > 0)) {
        // Si calcola la velocitá tra due boid e si aggiunge alla sommatoria.
        velali += (Boids[j].vel() - Boids[i].vel());
        count++;  // Si aggiunge un punto al contatore di Boid vicini.
      }
    }
    copyali[i].vel() = (velali / count) * rule.a();  // Regola di allineamento.
  }
  return copyali;
}
// Regola di coesione.
std::vector<Boid> coh(std::vector<Boid>& Boids, Rules const& rule) {
  std::vector<Boid> copycoh = Boids;
  for (size_t i; i < Boids.size(); i++) {  // Per ogni Boid.
    Bvec com = null;  // Definizione del vettore centro di massa.
    // Si azzera la velocitá e la posizione copia relativa all'i-esimo Boid.
    copycoh[i].vel() = null;
    copycoh[i].pos() = null;
    int count;                               // Contatore di Boid vicini
    for (size_t j; j < Boids.size(); j++) {  // Per ogni Boid.
      double ds = magn(Boids[i].pos() - Boids[j].pos());
      // Presi solo i Boid vicini diversi dal Boid stesso.
      if ((ds > 0) && (ds < rule.d())) {
        com = Boids[j].pos();  // Si calcola il centro di massa.
        count++;  // Si aggiunge un punot al contatore di Boid vicini.
      }
    }
    com = com / count;
    copycoh[i].vel() = (com - Boids[i].pos()) * rule.c();  // Regola di coesione
  }
  return copycoh;
}

#endif