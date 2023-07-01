#include "public/creature.h"

#include "gtest/gtest.h"
#include "public/creature_modifier.h"

class ChainResponsibility : public ::testing::Test {
  void SetUp() override {
    ASSERT_EQ(goblin_.attack_, 1);
    ASSERT_EQ(goblin_.defense_, 1);
  }

 protected:
  Creature goblin_ = Creature("Goblin", 1, 1);
  CreatureModifier root_ = CreatureModifier(goblin_);
};

TEST_F(ChainResponsibility, CreatureChainWalking) {
  DoubleAttackModifier double_at_0(goblin_);
  DoubleAttackModifier double_at_1(goblin_);
  IncreaseDefenseModifier inc_defense(goblin_);

  root_.Add(&double_at_0);
  root_.Add(&double_at_1);
  root_.Add(&inc_defense);

  // (at,de): (1,1)
  // First: (1,1) -> (2,1)
  // Second: (2,1) -> (4,1)
  // Third:(since at > 2 will not increase de)
  root_.Handle();
  EXPECT_EQ(goblin_.attack_, 4);
  EXPECT_EQ(goblin_.defense_, 1);
}

TEST_F(ChainResponsibility, CreatureNoWalking) {

  NoBonusesModifier no_bonus(goblin_);
  DoubleAttackModifier double_at_0(goblin_);
  DoubleAttackModifier double_at_1(goblin_);
  IncreaseDefenseModifier inc_defense(goblin_);

  root_.Add(&no_bonus);
  root_.Add(&double_at_0);
  root_.Add(&double_at_1);
  root_.Add(&inc_defense);

  // No walking of chain will happend because of NoBonusesModifier
  root_.Handle();
  EXPECT_EQ(goblin_.attack_, 1);
  EXPECT_EQ(goblin_.defense_, 1);
}