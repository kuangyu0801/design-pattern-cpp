#include <string>
#include <vector>

using std::string;
using std::vector;

// You are given a class called Sentence , which takes a string such as "hello
// world". You need to provide an interface such that the indexer (operator [] )
// returns a WordToken  that can be used to capitalize a particular word in the
// sentence.
// Typical use would be something like:
// Sentence sentence("hello world");
// sentence[1].capitalize = true;
// cout << sentence.str(); // prints "hello WORLD"
struct Sentence {
  struct WordToken {
    size_t index;
    bool capitalize;
  };

  string plain_text;
  vector<size_t> space_pos;
  vector<WordToken> tokens;

  Sentence(const string& text) : plain_text(text) {
    // todo
    for (size_t i = 0; i < plain_text.length(); i++) {
      if (plain_text[i] == ' ') {
        space_pos.push_back(i);
      }
    }
  }

  WordToken& operator[](size_t index) {
    tokens.emplace_back(WordToken{index, false});
    return *tokens.rbegin();
  }

  string str() const {
    string s;
    for (size_t i = 0; i < plain_text.length(); i++) {
      char c = plain_text[i];
      for (auto& token : tokens) {
        if (token.capitalize) {
          if (((token.index == 0ull) && (i < space_pos[token.index])) ||
              ((space_pos.size() == 1ull) &&
               (i > space_pos[token.index - 1])) ||
              ((i > space_pos[token.index - 1])) &&
                  (i < space_pos[token.index]))
            c = toupper(c);
        }
      }
      s += c;
    }
    return s;
  }
};