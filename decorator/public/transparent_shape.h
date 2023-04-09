
#include <cstdint>
#include <sstream>
#include <string>

#include "shape.h"

class TransparentShape : public Shape {
  using string = std::string;

 public:
  TransparentShape(Shape& shape, uint8_t transparency)
      : shape_(shape), transparency_(transparency) {}

  // Keeps the interface
  string Str() const override {
    std::ostringstream oss;
    oss << shape_.Str() << " has "
        << static_cast<float>(transparency_) / 255.f * 100.f
        << "% transparency";
    return oss.str();
  }

 private:
  uint8_t transparency_;
  Shape& shape_;
};

template <typename T>
class StaticTransparentShape : public T {
  using string = std::string;
  uint8_t transparency;

 public:
  StaticTransparentShape() {}

  template <typename... Args>
  StaticTransparentShape(const uint8_t transparency, Args... args)
      : T(std::forward<Args>(args)...), transparency{transparency} {}

  string Str() const override {
    std::ostringstream oss;
    oss << T::Str() << " has "
        << static_cast<float>(transparency) / 255.f * 100.f << "% transparency";
    return oss.str();
  }
};
