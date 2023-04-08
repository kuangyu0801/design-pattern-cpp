#pragma once

#include <complex>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct DiscriminantStrategy {
  virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy {
  double calculate_discriminant(double a, double b, double c) override {
    return b * b - 4 * a * c;
  }
};

struct RealDiscriminantStrategy : DiscriminantStrategy {
  double calculate_discriminant(double a, double b, double c) override {
    double result = b * b - 4 * a * c;
    return result >= 0 ? result : numeric_limits<double>::quiet_NaN();
  }
};