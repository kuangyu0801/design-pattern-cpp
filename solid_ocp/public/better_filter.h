#pragma once

#include <vector>

#include "filter.h"
#include "product.h"

struct BetterFilter : Filter<Product> {
  std::vector<Product*> filter(std::vector<Product*> items,
                               Specification<Product>& spec) override {
    std::vector<Product*> result;
    for (auto& p : items) {
      if (spec.is_satisfied(p)) {
        result.push_back(p);
      }
    }
    return result;
  }
};