#pragma once
#include "person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
 protected:
  // Only a reference.
  Person& person_;
  explicit PersonBuilderBase(Person& person) : person_{person} {}

 public:
  operator Person() const { return std::move(person_); }

  // builder facets

  PersonAddressBuilder Lives() const;
  PersonJobBuilder Works() const;
};

class PersonBuilder : public PersonBuilderBase {
 private:
  Person person_;

 public:
  PersonBuilder() : PersonBuilderBase{person_} {}
};