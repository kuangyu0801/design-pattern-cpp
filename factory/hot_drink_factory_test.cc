#include "public/hot_drink_factory.h"
#include "public/drink_factory.h"

#include "gtest/gtest.h"
#include "public/hot_drink.h"

unique_ptr<HotDrink> make_drink(string type) {
  unique_ptr<HotDrink> drink;
  if (type == "tea") {
    drink = make_unique<Tea>();
    drink->prepare(200);
  } else {
    drink = make_unique<Coffee>();
    drink->prepare(50);
  }
  return drink;
}

TEST(HotDrinkFactory, BasicTest) {
  auto d = make_drink("tea");

  DrinkFactory df;
  d = df.make_drink("coffee");
}