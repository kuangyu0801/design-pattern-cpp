#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

class FormattedText {
  string plain_text_;
  bool* caps;

 public:
  explicit FormattedText(const string& plain_text) : plain_text_{plain_text} {
    caps = new bool[plain_text.length()];
  }
  ~FormattedText() { delete[] caps; }
  void Capitalize(int start, int end) {
    for (int i = start; i <= end; ++i)
      caps[i] = true;
  }

  friend std::ostream& operator<<(std::ostream& os, const FormattedText& obj) {
    string s;
    for (int i = 0; i < obj.plain_text_.length(); ++i) {
      char c = obj.plain_text_[i];
      s += (obj.caps[i] ? toupper(c) : c);
    }
    return os << s;
  }
};

struct TextRange {
  int start, end;
  bool capitalize, bold, italic;

  bool covers(int position) const {
    return position >= start && position <= end;
  }
};

class BetterFormattedText {
 public:
  TextRange& AddRange(int start, int end) {
    formatting_.emplace_back(TextRange{start, end});
    return *formatting_.rbegin();
  }

  explicit BetterFormattedText(const string& plain_text)
      : plain_text_{plain_text} {}

  friend std::ostream& operator<<(std::ostream& os,
                                  const BetterFormattedText& obj) {
    string s;
    for (size_t i = 0; i < obj.plain_text_.length(); i++) {
      auto c = obj.plain_text_[i];
      for (const auto& rng : obj.formatting_) {
        if (rng.covers(i) && rng.capitalize)
          c = toupper(c);
        s += c;
      }
    }
    return os << s;
  }

 private:
  string plain_text_;
  vector<TextRange> formatting_;
};