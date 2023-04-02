#pragma once

struct IParticipant {
  virtual void notify(IParticipant* sender, int value) = 0;
};
