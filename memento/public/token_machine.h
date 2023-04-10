#pragma once

#include <iostream>
#include <memory>
#include <vector>

struct Token {
  int value;

  Token(int value) : value(value) {}
};

struct Memento {
  std::vector<std::shared_ptr<Token>> tokens;
};

struct TokenMachine {
  std::vector<std::shared_ptr<Token>> tokens;

  Memento AddToken(int value) {
    return AddToken(std::make_shared<Token>(value));
  }

  Memento AddToken(const std::shared_ptr<Token>& token) {
    tokens.push_back(token);
    Memento m;
    // Deep copy.
    for (auto t : tokens)
      m.tokens.emplace_back(std::make_shared<Token>(t->value));
    return m;
  }

  void Revert(const Memento& m) {
    tokens.clear();
    for (auto t : m.tokens)
      tokens.emplace_back(std::make_shared<Token>(t->value));
  }
};