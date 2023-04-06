#pragma once

#include <vector>

#include "specification.h"

template <typename T>
struct Filter {
  virtual std::vector<T*> filter(std::vector<T*> items,
                                 Specification<T>& spec) = 0;
};