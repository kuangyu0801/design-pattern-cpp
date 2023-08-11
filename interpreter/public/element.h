#pragma once

class Element {
 public:
  virtual ~Element() = default;
  virtual int eval() const = 0;
};