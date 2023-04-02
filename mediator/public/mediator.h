
#pragma once

#include "participant_interface.h"

#include <vector>

struct Mediator
{
    std::vector<IParticipant*> participants;
    void say(IParticipant* sender, int value)
    {
      for (auto p : participants)
        p->notify(sender, value);
    }
};