#pragma once

template <typename T>
class Property {
 public:
  Property(T value) : value_(value) {}

  // Operator overloading
  // Conversion operator: return T value.
  operator T() { return value_; }

  // Assignment
  T operator=(T new_value) { return value_ = new_value; }
 private:
  T value_;
};

class CreatureNative {
 public:
  int strength = 10;
  int agility = 10;
};

class CreatureWithProperty {
 public:
  Property<int> strength = 10;
  Property<int> agility = 10;
};

