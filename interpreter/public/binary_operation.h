#pragma once

#include <memory>

#include "element.h"

class BinaryOperation : public Element {
 public:
  enum class OpType { kAddition, kSubtraction } type;
  std::shared_ptr<Element> lhs, rhs;

  int eval() const override {
    // Recursive evaluate: lhs and rhs.
    if (type == OpType::kAddition) {
      return lhs->eval() + rhs->eval();
    } else {
      return lhs->eval() - rhs->eval();
    }
  }
};