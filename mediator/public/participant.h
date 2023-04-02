#pragma once

#include "participant_interface.h"
#include "mediator.h"

struct Participant : IParticipant
{
    int value{0};
    Mediator& mediator;

    Participant(Mediator &mediator) : mediator(mediator)
    {
      mediator.participants.push_back(this);
    }

    void notify(IParticipant *sender, int value) override {
      if (sender != this)
        this->value += value;
    }

    void say(int value)
    {
      mediator.say(this, value);
    }
};