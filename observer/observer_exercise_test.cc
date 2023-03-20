#include "gtest/gtest.h"

#include "public/game.h"
#include "public/rat.h"

// Demonstrate some basic assertions.
TEST(Observer, RatGame) {
  Game game;
  
  auto rat0 = std::make_unique<Rat>(game);
  EXPECT_EQ(rat0->attack, 1);
  auto rat1 = std::make_unique<Rat>(game);
  EXPECT_EQ(rat0->attack, 2);
  EXPECT_EQ(rat1->attack, 2);

  rat1.reset();
  EXPECT_EQ(rat0->attack, 1);
}