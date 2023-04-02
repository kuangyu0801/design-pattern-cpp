#pragma once
#include <algorithm>
#include <string>
#include <vector>

#include "people.h"

struct ChatRoom {
  using string = std::string;

  std::vector<Person*> people_;

  void Broadcast(const string& origin, const string& message);

  void Join(Person* p);

  void Message(const string& origin, const string& who, const string& message) {
    auto target = std::find_if(begin(people_),
                               end(people_),
                               [&](const Person* p) { return p->name_ == who; });
    if (target != end(people_)) {
      (*target)->Receive(origin, message);
    }
  }
};
