#include "public/person_factory.h"

#include "gtest/gtest.h"

namespace {
TEST(Evaluate, SimplePersonTest) {
  PersonFactory pf;

  auto p1 = pf.CreatePerson("Chris");
  ASSERT_EQ("Chris", p1.name);

  auto p2 = pf.CreatePerson("Sarah");
  ASSERT_EQ(1, p2.id) << "Expected the second created person's id to be = 1";
}

}  // namespace