#include "gtest/gtest.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#include "public/person.h"
#include "public/person_builder.h"
#include "public/person_address_builder.h"
#include "public/person_job_builder.h"

TEST(Builder, Person)
{
  Person p = Person::create()
    .lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
    .works().at("PragmaSoft").as_a("Consultant").earning(10e6);

  cout << p << endl;
}