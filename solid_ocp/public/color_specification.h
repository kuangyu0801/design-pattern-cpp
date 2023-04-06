#pragma once

#include "color.h"
#include "product.h"
#include "specification.h"

struct ColorSpecification : Specification<Product> {
  Color color;

  ColorSpecification(Color color) : color(color) {}

  bool is_satisfied(Product* item) const override {
    return item->color == color;
  }
};