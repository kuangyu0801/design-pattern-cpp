#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace state {
using namespace std;

enum class State {
  kOffHook,
  kConnecting,
  kConnected,
  kOnHold,
  kOnHook,
};

inline ostream& operator<<(ostream& os, const State& s) {
  switch (s) {
    case State::kOffHook:
      os << "off the hook";
      break;
    case State::kConnecting:
      os << "connecting";
      break;
    case State::kConnected:
      os << "connected";
      break;
    case State::kOnHold:
      os << "on hold";
      break;
    case State::kOnHook:
      os << "on the hook";
      break;
  }
  return os;
}

enum class Trigger {
  kCallDialed,
  kHungUp,
  kCallConnected,
  kPlacedOnHold,
  kTakenOffHold,
  kLeftMessage,
  kStopUsingPhone,
};

inline ostream& operator<<(ostream& os, const Trigger& t) {
  switch (t) {
    case Trigger::kCallDialed:
      os << "call dialed";
      break;
    case Trigger::kHungUp:
      os << "hung up";
      break;
    case Trigger::kCallConnected:
      os << "call connected";
      break;
    case Trigger::kPlacedOnHold:
      os << "placed on hold";
      break;
    case Trigger::kTakenOffHold:
      os << "taken off hold";
      break;
    case Trigger::kLeftMessage:
      os << "left message";
      break;
    case Trigger::kStopUsingPhone:
      os << "putting phone on hook";
      break;
    default:
      break;
  }
  return os;
}

}  // namespace state