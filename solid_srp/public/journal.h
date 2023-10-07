#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace srp {

using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;

struct Journal {
  string title_;
  vector<string> entries_;

  explicit Journal(const string& title) : title_{title} {}

  void Add(const string& entry);

  // persistence is a separate concern
  void Save(const string& filename);
};

void Journal::Add(const string& entry) {
  static int count = 1;
  stringstream buffer;
  buffer << count++ << ": " << entry;
  entries_.push_back(buffer.str());
}

// The function bundles persistance save with journal.
// This violates the single responsibility, ie, reason for a change.
// Therefore, we create another class `PersistenceManager` to take the
// responsiblity.
void Journal::Save(const string& filename) {
  ofstream ofs(filename);
  for (auto& s : entries_) {
    ofs << s << endl;
  }
}

struct PersistenceManager {
  static void Save(const Journal& j, const string& filename) {
    ofstream ofs(filename);
    for (auto& s : j.entries_) {
      ofs << s << endl;
    }
    ofs.close();
  }
};

}  // namespace srp