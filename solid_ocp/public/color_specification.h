#pragma once

#include "color.h"
#include "product.h"
#include "specification.h"

class ColorSpecification : public Specification<Product> {
 public:
  ColorSpecification(Color color) : color_(color) {}

  bool IsSatisfied(Product* item) const override {
    return (item->color == color_);
  }

 private:
  Color color_;
};