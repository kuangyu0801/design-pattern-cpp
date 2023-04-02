#pragma once
#include <string>
#include <vector>

struct ChatRoom;

struct Person {
  using string = std::string;

  string name_;
  ChatRoom* room_ = nullptr;
  std::vector<string> chat_log_;

  Person(const string& name);

  void Say(const string& message) const;
  void PrivateMessage(const string& who, const string& message) const;

  void Receive(const string& origin, const string& message);

  bool operator==(const Person& rhs) const;

  bool operator!=(const Person& rhs) const;
};
