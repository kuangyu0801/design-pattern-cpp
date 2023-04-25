#pragma once

#include <string>

#include "person_builder.h"


class PersonAddressBuilder : public PersonBuilderBase {
  typedef PersonAddressBuilder Self;

 public:
  explicit PersonAddressBuilder(Person& person) : PersonBuilderBase{person} {}

  Self& At(std::string street_address) {
    person_.street_address_ = street_address;
    return *this;
  }

  Self& WithPostcode(std::string post_code) {
    person_.post_code_ = post_code;
    return *this;
  }

  Self& In(std::string city) {
    person_.city_ = city;
    return *this;
  }
};