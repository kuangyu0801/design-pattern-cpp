#pragma once

#include <boost/bimap.hpp>
#include <boost/flyweight.hpp>
#include <cstdint>
#include <iostream>
#include <string>

using std::string;

struct NaiveUser {
  std::string first_name;
  std::string last_name;
};

// mmorpg
struct User {
  User(const string& first_name, const string& last_name)
      : first_name_id(add(first_name)), last_name_id(add(last_name)) {}

  const string& get_first_name() const {
    return names.left.find(last_name_id)->second;
  }

  const string& get_last_name() const {
    return names.left.find(last_name_id)->second;
  }

  static void info() {
    for (auto entry : names.left) {
      std::cout << "Key: " << entry.first << ", Value: " << entry.second
                << std::endl;
    }
  }

  friend std::ostream& operator<<(std::ostream& os, const User& obj) {
    return os << "first_name: " << obj.first_name_id << " "
              << obj.get_first_name() << " last_name: " << obj.last_name_id
              << " " << obj.get_last_name();
  }

 protected:
  // bidirectional map
  static boost::bimap<int, string> names;
  static int seed;

  static int add(const string& s) {
    auto it = names.right.find(s);
    if (it == names.right.end()) {
      // add it
      int id = ++seed;
      names.insert(boost::bimap<int, string>::value_type(seed, s));
      return id;
    }
    return it->second;
  }
  int first_name_id;
  int last_name_id;
};

int User::seed = 0;
boost::bimap<int, string> User::names;
