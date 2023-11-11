#pragma once

#include <vector>

#include "specification.h"

template <typename T>
class Filter {
  public:
  virtual std::vector<T*> FilterBySpec(std::vector<T*> items,
                                 Specification<T>& spec) = 0;
};