#pragma once

#include <iostream>

#include "relationship_browser.h"

struct Research  // high-level
{
  Research(RelationshipBrowser& browser) {
    for (auto& child : browser.FindAllChildOf("John")) {
      std::cout << "John has a child called " << child.name << std::endl;
    }
  }
  //  Research(const Relationships& relationships)
  //  {
  //    auto& relations = relationships.relations;
  //    for (auto&& [first, rel, second] : relations)
  //    {
  //      if (first.name == "John" && rel == Relationship::parent)
  //      {
  //        cout << "John has a child called " << second.name << endl;
  //      }
  //    }
  //  }
};