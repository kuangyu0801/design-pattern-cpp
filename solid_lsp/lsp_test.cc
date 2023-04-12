#include <iostream>

#include "gtest/gtest.h"
#include "public/rectangle.h"

void SetRectangleHeightToTen(Rectangle& r) {
  int w = r.GetWidth();
  r.SetHeight(10);

  std::cout << "expected area = " << (w * 10) << ", got " << r.Area()
            << std::endl;
}

TEST(LSP, ProcessBaseRectangle) {
  Rectangle r{5, 5};
  SetRectangleHeightToTen(r);
  EXPECT_EQ(r.GetHeight(), 10);
  EXPECT_EQ(r.GetWidth(), 5);
}

TEST(LSP, ProcessDerivedSquare) {
  Square s(5);
  SetRectangleHeightToTen(s);
  EXPECT_EQ(s.GetHeight(), 10);
  // Width is also set to 10, but we expect to change
  EXPECT_EQ(s.GetWidth(), 5);
}

TEST(LSP, ProcessBaseFactory) {
  Rectangle square = RectangleFactory::CreateRectangle(10, 7);
  EXPECT_EQ(square.GetWidth(), 10);
  EXPECT_EQ(square.GetHeight(), 7);
}

TEST(LSP, ProcessDerivedFactory) {
  Rectangle square = RectangleFactory::CreateSquare(5);
  EXPECT_EQ(square.GetHeight(), 5);
  EXPECT_EQ(square.GetWidth(), 5);
}