#include "public/person.h"
#include "public/person_builder.h"

PersonBuilder Person::Create()
{
  return PersonBuilder{};
}