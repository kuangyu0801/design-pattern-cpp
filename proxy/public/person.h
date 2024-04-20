
#pragma once

#include <string>

using std::string;

// You are given the Person  class and asked to write a ResponsiblePerson
// wrapper/proxy that does the following:
// Allows person to drink unless they are younger than 18 (in that case, return
// "too young")
// Allows person to drive unless they are younger than 16 (otherwise, "too
// young")
// In case of driving while drink, returns "dead"
// The interface of ResponsiblePerson  has to match that of Person , except for
// the constructor, which takes an underlying Person object.

class Person {
  friend class ResponsiblePerson;
  int age;

 public:
  Person(int age) : age(age) {}

  int get_age() const { return age; }
  void set_age(int age) { this->age = age; }

  string drink() const { return "drinking"; }
  string drive() const { return "driving"; }
  string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson {
 public:
  ResponsiblePerson(const Person& person) : person(person) {}
  // todo

  int get_age() const { return person.get_age(); }
  void set_age(int age) { person.set_age(age); }

  string drink() {
    return (person.get_age() < 18) ? "too young" : person.drink();
  }

  string drive() const {
    return (person.get_age() < 16) ? "too young" : person.drive();
  }

  string drink_and_drive() const { return "dead"; }

 private:
  Person person;
};