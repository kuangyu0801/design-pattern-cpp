#include "public/lock_state.h"

#include "gtest/gtest.h"

namespace {

TEST(Evaluate, TestSuccess) {
  CombinationLock cl({1, 2, 3});
  ASSERT_EQ("LOCKED", cl.status);

  cl.enter_digit(1);
  ASSERT_EQ("1", cl.status);

  cl.enter_digit(2);
  ASSERT_EQ("12", cl.status);

  cl.enter_digit(3);
  ASSERT_EQ("OPEN", cl.status);
}

TEST(Evaluate, TestFailure) {
  CombinationLock cl({1, 2, 3});
  ASSERT_EQ("LOCKED", cl.status);

  cl.enter_digit(1);
  ASSERT_EQ("1", cl.status);

  cl.enter_digit(2);
  ASSERT_EQ("12", cl.status);

  cl.enter_digit(5);
  ASSERT_EQ("ERROR", cl.status);
}

}  // namespace
