#pragma once

#include <iostream>
#include <string>

struct Person {
  int id;
  std::string name;
};

class PersonFactory {
 public:
  Person CreatePerson(const std::string& name) { return {id_++, name}; }

 private:
  int id_ = 0;
};