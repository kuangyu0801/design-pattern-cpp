#pragma once

#include "irat.h"
#include "game.h"

#include <algorithm>


class Rat : public IRat // observer
{
public:    
    Game& game;
    int attack{1};

    Rat(Game &game) : game(game) {
      // todo, obviously
      game.rats_.push_back(this);
      game.FireRatEnters(this);
    }

    ~Rat() { 
        // rat dies here!
        game.FireRatLeaves();
        auto it = std::remove(game.rats_.begin(), game.rats_.end(), this);
        game.rats_.erase(it);
    }
    
    void EnterGame(IRat* sender) override {
      if (sender != this) {
          attack += 1;
          game.FireNotify(sender);
      }
    }
    
    void LeaveGame()  override {
          attack -= 1;
    }
    
    void Notify(IRat* target) override {
      if (target == this) {
          attack += 1;
      }
    }
};