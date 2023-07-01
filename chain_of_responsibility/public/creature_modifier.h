#pragma once

#include "creature.h"

class CreatureModifier {
 public:
  explicit CreatureModifier(Creature& creature) : creature_(creature) {}


  virtual ~CreatureModifier() = default;

  void Add(CreatureModifier* creature) {
    if (next_ != nullptr) {
      next_->Add(creature);
    } else {
      next_ = creature;
    }
  }

  // Two approaches:
  // 1. Always call base handle(). There could be additional logic here.
  // 2. Only call base handle() when you cannot handle things yourself.
  // Walk through all the modifider
  virtual void Handle() {
    // Call the base to follow the entire chain.
    if (next_) {
      next_->Handle();
    }
  }

 protected:
  Creature& creature_;  // pointer or shared_ptr
 private:
  CreatureModifier* next_ = nullptr;  // unique_ptr
};

class DoubleAttackModifier : public CreatureModifier {
 public:
  explicit DoubleAttackModifier(Creature& creature)
      : CreatureModifier(creature) {}

  // Overrides the handle function.
  void Handle() override {
    creature_.attack_ *= 2;
    // Walk the chain of responsibility.
    CreatureModifier::Handle();
  }
};

class IncreaseDefenseModifier : public CreatureModifier {
 public:
  explicit IncreaseDefenseModifier(Creature& creature)
      : CreatureModifier(creature) {}

  void Handle() override {
    if (creature_.attack_ <= 2)
      creature_.defense_ += 1;
    CreatureModifier::Handle();
  }
};

class NoBonusesModifier : public CreatureModifier {
 public:
  explicit NoBonusesModifier(Creature& creature) : CreatureModifier(creature) {}

  void Handle() override {
    // no action: prevents walking.
  }
};