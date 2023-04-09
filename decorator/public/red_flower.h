#include <string>

#include "flower.h"

class RedFlower : public Flower {
 public:
  using string = std::string;
  Flower& flower;

  RedFlower(Flower& flower) : flower(flower) {}

  string Str() const override {
    string s = flower.Str();
    if (s.find("red") != string::npos)
      return s;
    else if (s.find("blue") != string::npos) {
      return s + " and red";
    } else
      return s + " that is red";
  }
};