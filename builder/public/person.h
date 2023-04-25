#pragma once

#include <iostream>
#include <string>

class PersonBuilder;

class Person {
  private:
  // address
  std::string street_address_, post_code_, city_;

  // employment
  std::string company_name_, position_;
  int annual_income_ = 0;
  // private constructor to force builder
  Person() { std::cout << "Person created\n"; }

 public:
  ~Person() { std::cout << "Person destroyed\n"; }

  static PersonBuilder Create();

  Person(Person&& other)
      : street_address_{std::move(other.street_address_)},
        post_code_{std::move(other.post_code_)},
        city_{std::move(other.city_)},
        company_name_{std::move(other.company_name_)},
        position_{std::move(other.position_)},
        annual_income_{other.annual_income_} {}

  Person& operator=(Person&& other) {
    if (this == &other)
      return *this;
    street_address_ = std::move(other.street_address_);
    post_code_ = std::move(other.post_code_);
    city_ = std::move(other.city_);
    company_name_ = std::move(other.company_name_);
    position_ = std::move(other.position_);
    annual_income_ = other.annual_income_;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Person& obj) {
    return os << "street_address: " << obj.street_address_
              << " post_code: " << obj.post_code_ << " city: " << obj.city_
              << " company_name: " << obj.company_name_
              << " position: " << obj.position_
              << " annual_income: " << obj.annual_income_;
  }

  friend class PersonBuilder;
  friend class PersonAddressBuilder;
  friend class PersonJobBuilder;
};
