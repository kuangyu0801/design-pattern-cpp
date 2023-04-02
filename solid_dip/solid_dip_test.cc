// A. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions.
// B. Abstractions should not depend on details.
//    Details should depend on abstractions.

#include "gtest/gtest.h"
#include "public/person.h"
#include "public/relationship.h"
#include "public/research.h"

TEST(Solid, DepndencyInversionPrinciple) {
  Person parent{"John"};
  Person child1{"Chris"};
  Person child2{"Matt"};

  Relationships relationships;
  relationships.AddParentAndChild(parent, child1);
  relationships.AddParentAndChild(parent, child2);

  Research research(relationships);
}