#pragma once

#include <string>

// wstring uses wchar_t as type, whereas string uses char.
// For Chinese character, 1 character takes 1 int wchar_t while 2 char.
using std::wstring;

class Pingable {
 public:
  virtual ~Pingable() = default;
  virtual wstring Ping(const wstring& message) = 0;
};

class Pong : public Pingable {
 public:
  wstring Ping(const wstring& message) override { return message + L" pong"; }
};
