#include "gtest/gtest.h"

#include "public/person_factory.h"

  TEST(Evaluate, SimplePersonTest)
  {
    PersonFactory pf;

    auto p1 = pf.create_person("Chris");
    ASSERT_EQ("Chris", p1.name);

    auto p2 = pf.create_person("Sarah");
    ASSERT_EQ(1, p2.id) << "Expected the second created person's id to be = 1";
  }