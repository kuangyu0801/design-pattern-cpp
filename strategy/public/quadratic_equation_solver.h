#pragma once

#include "discriminant_strategy.h"

class QuadraticEquationSolver {
  DiscriminantStrategy& strategy_;

 public:
  QuadraticEquationSolver(DiscriminantStrategy& strategy)
      : strategy_(strategy) {}

  tuple<complex<double>, complex<double>> solve(double a, double b, double c) {
    complex<double> disc(strategy_.calculate_discriminant(a, b, c), 0);
    auto root_disc = sqrt(disc);
    return {(-b + root_disc) / (2 * a), (-b - root_disc) / (2 * a)};
  };
};