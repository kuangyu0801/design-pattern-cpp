#include "public/adapter/square_adapter.h"

#include "gtest/gtest.h"


namespace {

TEST(Evaluate, SimpleTest) {
  Square sq(11);
  SquareToRectangleAdapter adapter(sq);
  ASSERT_EQ(121, adapter.area());
}

}  // namespace
