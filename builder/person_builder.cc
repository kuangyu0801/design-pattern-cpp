#include "public/person_builder.h"
#include "public/person_address_builder.h"
#include "public/person_job_builder.h"


PersonAddressBuilder PersonBuilderBase::Lives() const {
  return PersonAddressBuilder{person_};
}

PersonJobBuilder PersonBuilderBase::Works() const {
  return PersonJobBuilder{person_};
}
