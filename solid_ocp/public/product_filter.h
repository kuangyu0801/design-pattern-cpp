#pragma once

#include <vector>

#include "color.h"
#include "product.h"

class ProductFilter {
  // should not use alias in header for abbreviation.
  // typedef std::vector<Product*> Items;
 public:
  // Bad practice. Adding new filter would change the code.
  std::vector<Product*> FilterByColor(std::vector<Product*> items,
                                      const Color color) {
    std::vector<Product*> result;
    for (auto& i : items)
      if (i->color == color)
        result.push_back(i);
    return result;
  }

  std::vector<Product*> FilterBySize(std::vector<Product*> items,
                                     const Size size) {
    std::vector<Product*> result;
    for (auto& i : items)
      if (i->size == size)
        result.push_back(i);
    return result;
  }

  std::vector<Product*> FilterBySizeColor(std::vector<Product*> items,
                                          const Size size,
                                          const Color color) {
    std::vector<Product*> result;
    for (auto& i : items)
      if (i->size == size && i->color == color)
        result.push_back(i);
    return result;
  }
};