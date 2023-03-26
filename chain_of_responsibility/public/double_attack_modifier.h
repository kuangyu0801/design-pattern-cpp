
#pragma once

#include "creature_modifier.h"

class DoubleAttackModifier : public CreatureModifier {
public:
  explicit DoubleAttackModifier(Creature& creature)
    : CreatureModifier(creature)
  {
  }

  void Handle() override
  {
    creature_.attack_ *= 2;
    CreatureModifier::Handle();
  }
};