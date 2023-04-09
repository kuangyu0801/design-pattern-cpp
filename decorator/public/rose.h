
#include <string>

#include "flower.h"

class Rose : public Flower {
 public:
  std::string Str() const override { return "A rose"; }
};