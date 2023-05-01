#include "public/card_game.h"

#include "gtest/gtest.h"
// #include "helpers/iohelper.h"

// #include "exercise.cpp"

namespace {

TEST(CardGame, ImpasseTest) {
  Creature c1{1, 2};
  Creature c2{1, 2};
  TemporaryCardDamageGame game({c1, c2});
  ASSERT_EQ(-1, game.combat(0, 1));
  ASSERT_EQ(-1, game.combat(0, 1));
}

TEST(CardGame, TemporaryMurderTest) {
  Creature c1{1, 1};
  Creature c2{2, 2};
  TemporaryCardDamageGame game({c1, c2});
  ASSERT_EQ(1, game.combat(0, 1));
}

TEST(CardGame, DoubleMurderTest) {
  Creature c1{2, 2};
  Creature c2{2, 2};
  TemporaryCardDamageGame game({c1, c2});
  ASSERT_EQ(-1, game.combat(0, 1))
      << "The expectation here is that two 2/2 creatures kill each other";
}

TEST(CardGame, PermanentDamageDeathTest) {
  Creature c1{1, 2};
  Creature c2{1, 3};
  PermanentCardDamageGame game({c1, c2});
  ASSERT_EQ(-1, game.combat(0, 1))
      << "1/2 vs 1/3 should have no winner after first round of combat";
  ASSERT_EQ(1, game.combat(0, 1)) << "1/1 vs 1/2 here, so winner should be = 1";
}

}  // namespace