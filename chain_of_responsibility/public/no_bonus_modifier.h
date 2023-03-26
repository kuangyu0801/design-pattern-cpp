#pragma once

#include "creature_modifier.h"

class NoBonusesModifier : public CreatureModifier
{
public:
  explicit NoBonusesModifier(Creature& creature)
    : CreatureModifier(creature)
  {
  }

  void Handle() override
  {
    // nothing
  }
};