#pragma once

#include <vector>

#include "filter.h"
#include "product.h"

class BetterFilter : public Filter<Product> {
  public:
  std::vector<Product*> FilterBySpec(std::vector<Product*> items,
                               Specification<Product>& spec) override {
    std::vector<Product*> result;
    for (auto& p : items) {
      if (spec.IsSatisfied(p)) {
        result.push_back(p);
      }
    }
    return result;
  }
};