
#include "gtest/gtest.h"
#include "public/factory.h"


TEST(Factory, CreateFromMethod) {
  // will not work
  //Point p{ 1,2 };

  auto p = Point::NewPolar(5, M_PI_4);
  std::cout << p << std::endl;
}


TEST(Factory, CreateFromFactory) {
  // will not work
  //Point p{ 1,2 };

  auto p = PointFactory::NewPolar(5, M_PI_4);
  std::cout << p << std::endl;
}


TEST(Factory, CreateFromInnerFactory) {
// will not work
  //Point p{ 1,2 };

  //auto p = Point::inner_factory.NewPolar(5, M_PI_4);
  auto p = Point::GetInnerFactory().NewPolar(5, M_PI_4);
  std::cout << p << std::endl;
}