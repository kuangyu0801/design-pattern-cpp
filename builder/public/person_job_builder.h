#pragma once
#include "person_builder.h"

class PersonJobBuilder : public PersonBuilderBase {
  typedef PersonJobBuilder Self;

 public:
  explicit PersonJobBuilder(Person& person) : PersonBuilderBase{person} {}

  Self& At(std::string company_name) {
    person_.company_name_ = company_name;
    return *this;
  }

  Self& As(std::string position) {
    person_.position_ = position;
    return *this;
  }

  Self& Earning(int annual_income) {
    person_.annual_income_ = annual_income;
    return *this;
  }
};