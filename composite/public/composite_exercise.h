#pragma once

#include <iostream>
#include <string>
#include <vector>

struct ContainsIntegers {
  virtual int Sum() = 0;
};

struct SingleValue : ContainsIntegers {
  int value{0};

  SingleValue() = default;

  explicit SingleValue(const int value) : value{value} {}

  int Sum() override { return value; }
};

struct ManyValues : std::vector<int>, ContainsIntegers {
  void add(const int value) { push_back(value); }

  int Sum() override {
    int result = 0;
    for (auto it = begin(); it != end(); it++) {
      result += *it;
    }
    return result;
  }
};

inline int Sum(const std::vector<ContainsIntegers*> items) {
  int result = 0;
  for (auto item : items) {
    result += item->Sum();
  }
  return result;
}