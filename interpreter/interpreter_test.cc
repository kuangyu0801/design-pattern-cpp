#include <string>

#include "gtest/gtest.h"
#include "public/lex.h"
#include "public/token.h"
#include "public/parse.h"

using std::cout;
using std::endl;
using std::exception;
using std::string;
using Type = Token::Type;

TEST(Interpreter, Lex) {
  string input{"(14-4)+(12+1)"};  // see if you can make nested braces work
  auto tokens = lex(input);
  std::vector<Type> expected_tokens = {
      Type::kLeftPare, Type::kInteger, Type::kMinus, Type::kInteger, 
      Type::kRightPare, Type::kPlus, Type::kLeftPare,
      Type::kInteger, Type::kPlus, Type::kInteger, Type::kRightPare};
  // let's see the tokens
  for (int i = 0; i < tokens.size(); i += 1) {
    cout << tokens.at(i) << "   ";
    EXPECT_EQ(tokens.at(i).type_, expected_tokens.at(i));
  }
  cout << endl;

  try {
    auto parsed = ParseTokens(tokens);
    cout << input << " = " << parsed->eval() << endl;
    EXPECT_EQ(parsed->eval(), 23);
  } catch (const exception& e) {
    cout << e.what() << endl;
  }
}