#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

// inline constexpr string_view kLocked = "LOCKED";
// inline constexpr string_view kError = "ERROR";
// inline constexpr string_view kOpen = "OPEN";

class CombinationLock {
  vector<int> combination;
  int digits_entered = 0;
  bool failed = false;

  void reset() {
    status = "LOCKED";
    digits_entered = 0;
    failed = false;
  }

 public:
  string status;

  CombinationLock(const vector<int>& combination) : combination(combination) {
    reset();
  }

  void enter_digit(int digit) {
    if (status == "LOCKED") {
      status = "";
    }
    status += to_string(digit);
    if (combination[digits_entered] != digit) {
      failed = true;
    }
    digits_entered += 1;

    if (digits_entered == combination.size()) {
      status = failed ? "ERROR" : "OPEN";
    }
  }
};