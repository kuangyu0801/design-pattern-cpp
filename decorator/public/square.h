#pragma once

#include <sstream>
#include <string>

#include "shape.h"

class Square : public Shape {
 public:
  Square() = default;
  explicit Square(const float side) : side_(side) {}

  std::string Str() const override {
    std::ostringstream oss;
    oss << "A square with side: " << side_;
    return oss.str();
  }

 private:
  float side_;
};