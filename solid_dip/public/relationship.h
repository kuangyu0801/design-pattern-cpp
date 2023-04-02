
#pragma once
#include <string>
#include <tuple>
#include <vector>

#include "relationship_browser.h"

enum class Relationship { parent, child, sibling };

struct Relationships : RelationshipBrowser  // low-level
{
  std::vector<std::tuple<Person, Relationship, Person>> relations;

  void AddParentAndChild(const Person& parent, const Person& child) {
    relations.push_back({parent, Relationship::parent, child});
    relations.push_back({child, Relationship::child, parent});
  }

  std::vector<Person> FindAllChildOf(const std::string& name) override {
    std::vector<Person> result;
    for (auto&& [first, rel, second] : relations) {
      if (first.name == name && rel == Relationship::parent) {
        result.push_back(second);
      }
    }
    return result;
  }
};