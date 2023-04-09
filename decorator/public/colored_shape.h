#pragma once

// we are not changing the base class of existing
// objects

// cannot make, e.g., ColoredSquare, ColoredCircle, etc.
#include <sstream>
#include <string>

#include "shape.h"

class ColoredShape : public Shape {
  using string = std::string;

 private:
  Shape& shape_;
  string color_;

 public:
  ColoredShape(Shape& shape, const string& color)
      : shape_(shape), color_(color) {}

  // Keeps the interface
  string Str() const override {
    std::ostringstream oss;
    oss << shape_.Str() << " has the color " << color_;
    return oss.str();
  }
};

// mixin inheritance, unique to C++ only
// note: class, not typename
template <typename T>
class StaticColoredShape : public T {
  using string = std::string;
  static_assert(std::is_base_of<Shape, T>::value,
                "Template argument must be a Shape");

  string color_;

 public:
  // need this (or not!)
  StaticColoredShape() {}

  template <typename... Args>
  StaticColoredShape(const string& color, Args... args)
      // perfect forwarding
      : T(std::forward<Args>(args)...),
        color_(color)  // you cannot call base class ctor here
                       // b/c you have no idea what it is
  {}

  string Str() const override {
    std::ostringstream oss;
    // TODO: Why do we call T::Str() instead od T.Str()
    oss << T::Str() << " has the color " << color_;
    return oss.str();
  }
};