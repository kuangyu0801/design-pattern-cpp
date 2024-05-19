#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "public/flyweight_exercise.h"
#include "public/format_text.h"
#include "public/user.h"

namespace {

using std::cout;
using std::endl;

TEST(Flyweight, Basic) {
  User john_doe{"John", "Doe"};
  User jane_doe{"Jane", "Doe"};

  cout << "John " << john_doe << endl;
  cout << "Jane " << jane_doe << endl;

  User::info();
}

TEST(Flyweight, FormatText) {
  FormattedText ft("This is a brave new world");
  ft.Capitalize(10, 15);
  cout << ft << endl;
  std::ostringstream oss;
  oss << ft;
  std::string output = oss.str();
  EXPECT_STREQ(output.data(), "This is a BRAVE new world");
}

TEST(Flyweight, BetterFormatText) {
  BetterFormattedText ft("This is a brave new world");
  ft.AddRange(10, 15).capitalize = true;
  cout << ft << endl;
  std::ostringstream oss;
  oss << ft;
  std::string output = oss.str();
  EXPECT_STREQ(output.data(), "This is a BRAVE new world");
}

TEST(Flyweight, Exercise) {
  Sentence sentence("hello world");
  sentence[1].capitalize = true;
  cout << sentence.str();
  ;
  EXPECT_STREQ(sentence.str().data(), "hello WORLD");
}

TEST(Flyweight, Exercise2) {
  Sentence sentence("hello world");
  sentence[0].capitalize = true;
  cout << sentence.str();
  EXPECT_STREQ(sentence.str().data(), "HELLO world");
}

TEST(Flyweight, ExerciseSecond) {
  Sentence sentence("alpha beta gamma");
  sentence[1].capitalize = true;
  cout << sentence.str();
  EXPECT_STREQ(sentence.str().data(), "alpha BETA gamma");
}
}  // namespace