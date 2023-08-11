#pragma once
#include <ostream>
#include <string>

class Token {
 public:
  enum class Type { kInteger, kPlus, kMinus, kLeftPare, kRightPare } type_;
  std::string text_;

  explicit Token(Type type, const std::string& text)
      : type_{type}, text_{text} {}

  friend std::ostream& operator<<(std::ostream& os, const Token& obj) {
    return os << "`" << obj.text_ << "`";
  }
};