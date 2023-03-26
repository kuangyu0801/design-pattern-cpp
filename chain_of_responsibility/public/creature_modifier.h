#pragma once

#include "creature.h"

class CreatureModifier {
    CreatureModifier* next_ = nullptr; // unique_ptr
protected:
    Creature& creature_; // pointer or shared_ptr
public:
    explicit CreatureModifier(Creature& creature) : creature_(creature) {}
    virtual ~CreatureModifier() = default;

    void Add(CreatureModifier* creature) {
        if (next_) {
            next_->Add(creature);
        } else {
            next_ = creature;
        }
    }

    // two approaches:

    // 1. Always call base handle(). There could be additional logic here.
    // 2. Only call base handle() when you cannot handle things yourself.
    // Walk through all the modifider
    virtual void Handle() {
        // Call the base
        if (next_) {
            next_->Handle();
        }
}
};