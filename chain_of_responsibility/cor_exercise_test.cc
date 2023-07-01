// # TODO(#13): Enable example using boosts
#include "public/cor_exercise.h"

#include <iostream>

#include "gtest/gtest.h"

TEST(Evaluate, ManyGoblinsTest) {
  Game game;
  Goblin goblin1{game};
  game.creatures.push_back(&goblin1);

  std::cout << "Checking that a baseline goblin is a 1/1...\n";

  ASSERT_EQ(1, goblin1.GetAttack());
  ASSERT_EQ(1, goblin1.GetDefense());

  std::cout << "Adding a second goblin, now they should be 1/2...\n";
  Goblin goblin2{game};
  game.creatures.push_back(&goblin2);

  ASSERT_EQ(1, goblin1.GetAttack());
  ASSERT_EQ(2, goblin1.GetDefense());

  std::cout << "Adding a goblin king, now a goblin should be 2/3...\n";
  GoblinKing goblin3{game};
  game.creatures.push_back(&goblin3);

  ASSERT_EQ(2, goblin1.GetAttack());
  ASSERT_EQ(3, goblin1.GetDefense());
}