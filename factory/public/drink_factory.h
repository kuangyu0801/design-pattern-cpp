#pragma once
#include <functional>
#include <map>
#include <string>

#include "coffee_factory.h"
#include "hot_drink.h"
#include "tea_factory.h"

struct HotDrink;

class DrinkFactory {
  // Composition
  map<string, unique_ptr<HotDrinkFactory>> hot_factories;

 public:
  DrinkFactory() {
    hot_factories["coffee"] = make_unique<CoffeeFactory>();
    hot_factories["tea"] = make_unique<TeaFactory>();
  }

  unique_ptr<HotDrink> make_drink(const string& name) {
    auto drink = hot_factories[name]->make();
    drink->prepare(200);  // oops!
    return drink;
  }
};

// This is a functional approach compared with abstract/inheritance approach.
class DrinkWithVolumeFactory {
  // Storing callable objects as value in a map.
  map<string, function<unique_ptr<HotDrink>()>> factories;

 public:
  DrinkWithVolumeFactory() {
    factories["tea"] = [] {
      auto tea = make_unique<Tea>();
      tea->prepare(200);
      return tea;
    };
  }

  unique_ptr<HotDrink> make_drink(const string& name);
};

inline unique_ptr<HotDrink> DrinkWithVolumeFactory::make_drink(
    const string& name) {
  return factories[name]();
}
