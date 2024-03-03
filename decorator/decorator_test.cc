#include <iostream>

#include "gtest/gtest.h"
#include "public/circle.h"
#include "public/colored_shape.h"
#include "public/logger.h"
#include "public/shape.h"
#include "public/square.h"
#include "public/transparent_shape.h"

using namespace std;

namespace {

TEST(Decorator, DynamicDecoratorShape) {
  Square square(5);
  ColoredShape red_square(square, "red");
  TransparentShape transparent_shape(red_square, 150);
  cout << square.Str() << endl
       << red_square.Str() << endl
       << transparent_shape.Str() << endl;
}

TEST(Decorator, DynamicDecoratorCircle) {
  Circle circle{5};
  cout << circle.Str() << endl;

  ColoredShape red_circle{circle, "red"};
  cout << red_circle.Str() << endl;

  // Cannot call Resize(), even if we know the underlying type is circle
  // red_circle.resize(); // oops

  TransparentShape red_half_visible_circle{red_circle, 128};
  cout << red_half_visible_circle.Str() << endl;
}

TEST(Decorator, StaticDecoratorCircle) {
  // won't work without a default constructor
  StaticColoredShape<Circle> green_circle("green", 5);
  green_circle.Resize(10);
  cout << green_circle.Str() << endl;
}

TEST(Decorator, StaticDecoratorShape) {
  // won't work without a default constructor

  StaticTransparentShape<StaticColoredShape<Square>> blue_invisible_square(
      100, "blue", 321);
  cout << blue_invisible_square.Str() << endl;
}

TEST(Decorator, StaticFunctionDecoratorWithoutArgReturn) {
  // Logger([]() {cout << "Hello" << endl; }, "HelloFunction")();
  // cannot do this
  // make_logger2([]() {cout << "Hello" << endl; }, "HelloFunction")();
  auto call =
      MakeStaticLogger([]() { cout << "Hello!" << endl; }, "HelloFunction");
  call();
}

double Add(double a, double b) {
  cout << a << "+" << b << "=" << (a + b) << endl;
  return a + b;
}

TEST(Decorator, StaticFunctionDecoratorWithArgReturn) {
  auto call =
      // StaticLoggerArgs<double(double, double)>(Add, "HelloFunction");
      MakeStaticLoggerArgs(Add, "HelloFunction");
  EXPECT_EQ(call(1.5, 2.2), 3.7);
}

}  // namespace
