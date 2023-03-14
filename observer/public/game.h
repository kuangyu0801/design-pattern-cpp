#pragma once

#include <vector>

#include "irat.h"

class Game {
public:    
    std::vector<IRat*> rats_;

    void FireRatEnters(IRat* sender) {
        for (auto rat : rats_) {
            rat->EnterGame(sender);
        }
    }
    
    void FireRatLeaves() {
        for (auto rat : rats_) {
            rat->LeaveGame();
        }
    }
    
    void FireNotify(IRat* target) {
        for (auto rat : rats_) {
            rat->Notify(target);
        }
    }
};