#pragma once

#include <cmath>
#include <iostream>

enum class PointType { cartesian, polar };

class Point {
 private:
  // Private constuctor to prevent user for calling directly
  Point(const float x, const float y) : x_(x), y_(y) {}

  // Inner Factory class
  class PointInnerFactory {
   public:
    static Point NewCartesian(float x, float y) { return Point{x, y}; }

    static Point NewPolar(float r, float theta) {
      return Point{r * cos(theta), r * sin(theta)};
    }
  };

  float x_, y_;

 public:
  // Problem: The constructor is not descriptive
  // a, b are both required for cartesian and polar coordinates
  // This makes construction confusing
  /*
  Point(float a, float b, PointType type = PointType::cartesian) {
    if (type == PointType::cartesian) {
        x = a; b = y;
    } else {
        x = a*cos(b);
        y = a*sin(b);
    }
  }
  */

  static PointInnerFactory& GetInnerFactory() {
    static PointInnerFactory inner_factory;
    return inner_factory;
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
    return os << "x: " << obj.x_ << " y: " << obj.y_;
  }

  // Factory methods
  static Point NewCartesian(float x, float y) { return {x, y}; }
  static Point NewPolar(float r, float theta) {
    return {r * cos(theta), r * sin(theta)};
  }

  // Warning: This breaks OCP
  friend class PointFactory;


};

class PointFactory {
 public:
  static Point NewCartesian(float x, float y) { return Point{x, y}; }

  static Point NewPolar(float r, float theta) {
    return Point{r * cos(theta), r * sin(theta)};
  }
};
