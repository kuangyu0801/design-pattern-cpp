#include <vector>

#include "gtest/gtest.h"
#include "public/better_filter.h"
#include "public/color.h"
#include "public/color_specification.h"
#include "public/filter.h"
#include "public/product.h"
#include "public/product_filter.h"
#include "public/size.h"
#include "public/specification.h"

using namespace std;

namespace {

class OpenClosePrincipleTest : public ::testing::Test {
 public:
  Product apple_{"Apple", Color::kGreen, Size::kSmall};
  Product tree_{"Tree", Color::kGreen, Size::kLarge};
  Product house_{"House", Color::kBlue, Size::kLarge};
  const vector<Product*> products_{&apple_, &tree_, &house_};
};

TEST_F(OpenClosePrincipleTest, NonExtensibleFilter) {
  ProductFilter product_fileter;
  vector<Product*> blue_products =
      product_fileter.by_color(products_, Color::kBlue);
  EXPECT_EQ(blue_products.size(), 1);
  EXPECT_EQ(blue_products.at(0), &house_);
}

TEST_F(OpenClosePrincipleTest, ExtensibleFilter) {
  BetterFilter better_filter;
  ColorSpecification color_spec(Color::kBlue);
  vector<Product*> blue_products = better_filter.filter(products_, color_spec);
  EXPECT_EQ(blue_products.size(), 1);
  EXPECT_EQ(blue_products.at(0), &house_);
}

}  // namespace