#include "public/person_builder.h"
#include "public/person_address_builder.h"
#include "public/person_job_builder.h"


PersonAddressBuilder PersonBuilderBase::lives() const {
  return PersonAddressBuilder{person};
}

PersonJobBuilder PersonBuilderBase::works() const {
  return PersonJobBuilder{person};
}
