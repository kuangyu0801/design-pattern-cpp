#include <string>

#include "flower.h"

class BlueFlower : public Flower {
 public:
  using string = std::string;
  Flower& flower;

  BlueFlower(Flower& flower) : flower(flower) {}

  string Str() const override {
    string s = flower.Str();
    if (s.find("blue") != string::npos)
      return s;
    else if (s.find("red") != string::npos) {
      return s + " and blue";
    } else
      return s + " that is blue";
  }
};