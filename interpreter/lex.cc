#include "public/lex.h"
#include "public/token.h"

#include <sstream>
using namespace std;
vector<Token> lex(const string& input) {
  vector<Token> result;

  for (int i = 0; i < input.size(); ++i) {
    switch (input[i]) {
      case '+':
        result.push_back(Token{Token::Type::kPlus, "+"});
        break;
      case '-':
        result.push_back(Token{Token::Type::kMinus, "-"});
        break;
      case '(':
        result.push_back(Token{Token::Type::kLeftPare, "("});
        break;
      case ')':
        result.push_back(Token{Token::Type::kRightPare, ")"});
        break;
      default:
        // number
        ostringstream buffer;
        buffer << input[i];
        for (int j = i + 1; j < input.size(); ++j) {
          if (isdigit(input[j])) {
            buffer << input[j];
            ++i;
          } else {
            result.push_back(Token{Token::Type::kInteger, buffer.str()});
            break;
          }
        }
    }
  }

  return result;
}