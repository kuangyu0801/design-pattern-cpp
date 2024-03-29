#pragma once

#include <iostream>
#include <string>
using namespace std;

class Creature {
 public:

  explicit Creature(const string& name, const int attack, const int defense)
      : name_(name), attack_(attack), defense_(defense) {}

  friend ostream& operator<<(ostream& os, const Creature& obj) {
    return os << "name: " << obj.name_ << " attack: " << obj.attack_
              << " defense: " << obj.defense_;
  }

  std::string name_;
  int attack_;
  int defense_;
};
