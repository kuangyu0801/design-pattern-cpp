#pragma once

#include <array>
// Only supports C++20.
// #include <numeric>
#include <algorithm>

class Creature {
  // Having member variables for each instance is not scalable.
  //  int strength;
  //  int agility;
  //  int intelligenece;
  //  int Sum() {
  //     return
  //     strength + agility + intelligenece;
  //  }

 public:
  int get_strength() { return abilities[kStrength]; }
  void set_strength(int val) { abilities[kStrength] = val; }

  int get_agility() { return abilities[kAgility]; }

  void set_agility(int val) { abilities[kAgility] = val; }

  int get_intelligence() { return abilities[kInitelligence]; }

  void set_intelligence(int val) { abilities[kInitelligence] = val; }

  int Sum() const {
    int sum = 0;
    for (auto& ability : abilities) {
      sum += ability;
    }
    return sum;
    // return std::accumulate(abilities.begin(), abilities.end());
  }

  double Average() const { return Sum() / (double)kCount; }
  int max() const {
    return *std::max_element(abilities.begin(), abilities.end());
  }

 private:
  enum Abilities { kStrength, kAgility, kInitelligence, kCount };
  std::array<int, kCount> abilities;
};