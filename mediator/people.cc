#include <iostream>
#include <string>

#include "public/chat_room.h"
#include "public/people.h"

Person::Person(const string& name) : name_(name) {}

void Person::Say(const string& message) const {
  room_->Broadcast(name_, message);
}

void Person::PrivateMessage(const string& who, const string& message) const {
  room_->Message(name_, who, message);
}

void Person::Receive(const string& origin, const string& message) {
  string s{origin + ": \"" + message + "\""};
  std::cout << "[" << name_ << "'s chat session]" << s << "\n";
  chat_log_.emplace_back(s);
}

bool Person::operator==(const Person& rhs) const { return name_ == rhs.name_; }

bool Person::operator!=(const Person& rhs) const { return !(rhs == *this); }
