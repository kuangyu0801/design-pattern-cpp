#include <iostream>

#include "gtest/gtest.h"
#include "public/prototype_exercise.h"
#include "public/record.h"

namespace {
TEST(ProtoType, DeepCopyContact) {
  // this is tedious since all people are in the same building.
  Address john_addr("123 East Dr", "London", 111);
  Address jane_addr("123 East Dr", "London", 112);

  DeepCopyContact john{"John Doe", john_addr};
  DeepCopyContact jane{"Jane Doe", jane_addr};
}

TEST(ProtoType, PointerContact) {
  PointerContact john{"John Doe", new Address("123 East Dr", "London", 111)};
  PointerContact jane = john;  // shallow copy
  jane.name = "Jane Doe";
  // Modifying jane will also modying john.
  jane.address->suite = 103;

  EXPECT_EQ(jane.address->suite, 103);
  EXPECT_EQ(john.address->suite, 103);
}

TEST(ProtoType, DeepPointerContact) {
  DeepPointerContact john{"John Doe",
                          new Address("123 East Dr", "London", 111)};
  DeepPointerContact jane = john;  // deep copy

  jane.name = "Jane Doe";
  jane.address->suite = 103;

  EXPECT_EQ(jane.address->suite, 103);
  EXPECT_EQ(john.address->suite, 111);
}

TEST(ProtoType, EmployeeFactory) {
  auto john = EmployeeFactory::NewEmployeeFromPrototype("John", 111);
  EXPECT_EQ(john->address->city, "London");
  EXPECT_EQ(john->address->street, "123 East Dr");
  EXPECT_EQ(john->address->suite, 111);
  EXPECT_EQ(john->name, "John");
}

TEST(ProtoType, LinePointExercise) {
  Line line{new Point{3, 3}, new Point{10, 10}};

  auto line_copy = line.deep_copy();
  line.start->x = line.start->y = line.end->y = line.end->y = 0;

  ASSERT_EQ(3, line_copy.start->x);
  ASSERT_EQ(3, line_copy.start->y);
  ASSERT_EQ(10, line_copy.end->x);
  ASSERT_EQ(10, line_copy.end->y);
}

}  // namespace