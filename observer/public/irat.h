#pragma once

class IRat {
 public:
  virtual void EnterGame(IRat* ) = 0;
  virtual void LeaveGame() = 0;
  virtual void Notify(IRat* ) = 0;
};
