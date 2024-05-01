#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

// TODO(#36): Use serialization example
// #include <boost/serialization>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/serialization.hpp>

using std::ostream;
using std::string;

struct Address {
  string street;
  string city;
  int suite;

  Address(const string& street, const string& city, const int suite)
      : street{street}, city{city}, suite{suite} {}

  /*Address(const Address& other)
    : street{other.street},
      city{other.city},
      suite{other.suite}
  {
  }*/

  friend ostream& operator<<(ostream& os, const Address& obj) {
    return os << "street: " << obj.street << " city: " << obj.city
              << " suite: " << obj.suite;
  }
};

struct DeepCopyContact {
  string name;
  Address address;

  DeepCopyContact(string name, Address& address)
      : name{name}, address{address} {
    // this->address = new Address{ *address };
  }

  DeepCopyContact(const DeepCopyContact& other)
      : name{other.name}, address{other.address} {}
};

struct PointerContact {
  string name;
  Address* address;

  PointerContact(string name, Address* address)
      : name(name), address(address) {}

  PointerContact(const PointerContact& other)
      : name(other.name),
        // shallow copy
        address(other.address) {}
};

struct DeepPointerContact : public PointerContact {
  DeepPointerContact(string name, Address* address)
      : PointerContact(name, address) {}

  DeepPointerContact(const DeepPointerContact& other)
      : PointerContact(other.name,
                       // deep copy
                       new Address(other.address->street,
                                   other.address->city,
                                   other.address->suite)) {}
};

struct Contact {
  string name;
  Address* address;

  Contact(string name, Address* address) : name(name), address(address) {}

  Contact(const Contact& other)
      : name{other.name},
        // shallow copy
        address(new Address(
            other.address->street, other.address->city, other.address->suite)) {
  }

  friend ostream& operator<<(ostream& os, const Contact& contact) {
    os << "name:" << contact.name << " address: " << *contact.address;
    return os;
  }

 private:
  friend class boost::serialization::access;
};

struct EmployeeFactory {
  static std::unique_ptr<Contact> NewEmployeeFromPrototype(const string& name,
                                                           const int suite) {
    static Contact prototype("", new Address("123 East Dr", "London", 0));
    return NewEmployee(name, suite, prototype);
  }

 private:
  static std::unique_ptr<Contact> NewEmployee(const string& name,
                                              const int suite,
                                              const Contact& prototype) {
    auto result = std::make_unique<Contact>(prototype);
    result->name = name;
    result->address->suite = suite;
    return result;
  }
};