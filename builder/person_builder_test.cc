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
  Person p = Person::Create()
    .Lives().At("123 London Road").WithPostcode("SW1 1GB").In("London")
    .Works().At("PragmaSoft").As("Consultant").Earning(10e6);

  cout << p << endl;
}