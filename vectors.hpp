#ifndef VECOTRS_HPP
#define VECTORS_HPP
#include <cmath>
#include <iostream>

class Bvec {
 private:
  double x_{};
  double y_{};
  double z_{};

 public:
  Bvec(double x, double y, double z) : x_{x}, y_{y}, z_{z} {}
  double x() const { return x_; };
  double y() const { return y_; };
  double z() const { return z_; };
};

Bvec operator+(Bvec const& v1, Bvec const& v2) {
  Bvec res = {v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z()};
  return res;
}

Bvec operator-(Bvec const& v1, Bvec const& v2) {
  Bvec res = {v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z()};
  return res;
}

double operator*(Bvec const& v1, Bvec const& v2) {
  double res = v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
  return res;
}

Bvec operator*(Bvec const& v1, double const& s) {
  Bvec res = {v1.x() * s, v1.y() * s, v1.z() * s};
  return res;
}

Bvec operator/(Bvec const& v1, double const& s) {
  Bvec res = {v1.x() / s, v1.y() / s, v1.z() / s};
  return res;
}

bool operator==(Bvec const& v1, Bvec const& v2) {
  return (v1.x() == v2.x()) && (v1.y() == v2.y()) && (v1.z() == v2.z());
}
double norm(Bvec const& v1) { return sqrt(v1 * v1); }
#endif