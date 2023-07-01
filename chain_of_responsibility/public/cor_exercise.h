#pragma once
#include <vector>

using ::std::vector;

// You are given a game scenario with classes Goblin  and GoblinKing .
// Please implement the following rules:

// A goblin has base 1 attack/1 defense (1/1), a goblin king is 3/3.
// When the Goblin King is in play, every other goblin gets +1 Attack.
// Goblins get +1 to Defense for every other Goblin in play (a GoblinKing is a
// Goblin!).

// forward declaration.
class Creature;

struct Game {
  vector<Creature*> creatures;
};

struct StatQuery {
  enum class Statistic { kAttack, kDefense } statistic;
  int result;
};

class Creature {
 protected:
  Game& game;
  int base_attack_, base_defense_;

 public:
  Creature(Game& game, int base_attack, int base_defense)
      : game(game), base_attack_(base_attack), base_defense_(base_defense) {}

  virtual int GetAttack() = 0;
  virtual int GetDefense() = 0;
  virtual void Query(void* source, StatQuery& sq) = 0;
};

class Goblin : public Creature {
 public:
  Goblin(Game& game, int base_attack, int base_defense)
      : Creature(game, base_attack, base_defense) {}

  Goblin(Game& game) : Creature(game, 1, 1) {}

  int GetAttack() override {
    return GetStatistic(StatQuery::Statistic::kAttack);
  }

  int GetDefense() override {
    return GetStatistic(StatQuery::Statistic::kDefense);
  }

  void Query(void* source, StatQuery& sq) override {
    if (source == this) {
      switch (sq.statistic) {
        case StatQuery::Statistic::kAttack:
          sq.result += base_attack_;
          break;
        case StatQuery::Statistic::kDefense:
          sq.result += base_defense_;
          break;
      }
    } else {
      if (sq.statistic == StatQuery::Statistic::kDefense) {
        sq.result++;
      }
    }
  }

 private:
  int GetStatistic(StatQuery::Statistic stat) {
    StatQuery q{stat, 0};
    // Walks through all the chain.
    for (auto c : game.creatures)
      c->Query(this, q);
    return q.result;
  }
};

class GoblinKing : public Goblin {
 public:
  GoblinKing(Game& game) : Goblin(game, 3, 3) {}

  void Query(void* source, StatQuery& sq) override {
    if (source != this && sq.statistic == StatQuery::Statistic::kAttack) {
      sq.result++;
    } else
      Goblin::Query(source, sq);
  }
};