#include "element.h"

class Integer : public Element {
 private:
  int value_;

 public:
  explicit Integer(const int value) : value_(value) {}
  int eval() const override { return value_; }
};