#include "public/visitor_exercise.h"

#include <iostream>

#include "gtest/gtest.h"

namespace visitor {
namespace exercise {
namespace {

TEST(VisitorPattern, SimpleAddition) {
  Value v{2};
  AdditionExpression simple{v, v};
  ExpressionPrinter ep;
  ep.Visit(simple);
  ASSERT_EQ("(2+2)", ep.str());
}

TEST(VisitorPattern, ProductOfAdditionAndValue) {
  Value _2{2};
  Value _3{3};
  Value _4{4};
  AdditionExpression ae{_2, _3};
  MultiplicationExpression expr{ae, _4};
  ExpressionPrinter ep;
  ep.Visit(expr);
  ASSERT_EQ("(2+3)*4", ep.str());
}

}  // namespace
}  // namespace exercise
}  // namespace visitor