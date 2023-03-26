#include "gtest/gtest.h"

#include "public/creature.h"

#include "public/double_attack_modifier.h"
#include "public/increase_defense_modifier.h"
#include "public/no_bonus_modifier.h"

TEST(ChainResponsibility, Hello) {
    ASSERT_TRUE(true);
}

TEST(ChainResponsibility, Creature) {
    Creature goblin("Creature", 1, 1);
    CreatureModifier base_mod(goblin);
    DoubleAttackModifier attack_mod_0(goblin);
    DoubleAttackModifier attack_mod_1(goblin);
    IncreaseDefenseModifier defense_mod(goblin);

    base_mod.Add(&attack_mod_0);
    base_mod.Add(&attack_mod_1);
    base_mod.Add(&defense_mod);

    base_mod.Handle();
    EXPECT_EQ(goblin.attack_, 4);
    EXPECT_EQ(goblin.defense_, 1);
}