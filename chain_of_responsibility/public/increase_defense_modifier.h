#pragma once

#include "creature_modifier.h"

class IncreaseDefenseModifier : public CreatureModifier
{
public:
  explicit IncreaseDefenseModifier(Creature& creature)
    : CreatureModifier(creature)
  {
  }


  void Handle() override
  {
    if (creature_.attack_ <= 2)
      creature_.defense_ += 1;
    CreatureModifier::Handle();
  }
};