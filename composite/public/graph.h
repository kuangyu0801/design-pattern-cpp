#pragma once

#include <iostream>
#include <memory>
#include <vector>


struct GraphicObject {
  virtual void Draw() = 0;
};

struct Circle : GraphicObject {
  void Draw() override { std::cout << "Circle" << std::endl; }
};

// Group also inherits Graphic 
struct Group : GraphicObject {
  std::string name;

  explicit Group(const std::string& name) : name{name} {}

  void Draw() override {
    std::cout << "Group " << name.c_str() << " contains:" << std::endl;
    for (auto&& o : objects)
      o->Draw();
  }

  std::vector<GraphicObject*> objects;
};
