#pragma once

#include <string>
#include <vector>

#include "person.h"

struct RelationshipBrowser {
  virtual std::vector<Person> FindAllChildOf(const std::string& name) = 0;
};