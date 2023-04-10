#include "public/token_machine.h"

#include "gtest/gtest.h"

namespace {
using std::cout;

TEST(Evaluate, SingleTokenTest) {
  TokenMachine tm;
  auto m = tm.AddToken(123);
  tm.AddToken(456);
  tm.Revert(m);
  ASSERT_EQ(1, tm.tokens.size());
  ASSERT_EQ(123, tm.tokens[0]->value);
}

TEST(Evaluate, TwoTokenTest) {
  TokenMachine tm;
  tm.AddToken(1);
  auto m = tm.AddToken(2);
  tm.AddToken(3);
  tm.Revert(m);
  ASSERT_EQ(2, tm.tokens.size());
  ASSERT_EQ(1, tm.tokens[0]->value)
      << "First toke should have value 1, you got " << tm.tokens[0]->value;
  ASSERT_EQ(2, tm.tokens[1]->value);
}

TEST(Evaluate, FiddledTokenTest) {
  TokenMachine tm;
  cout << "Made a token with value=111 and kept a reference\n";
  auto token = std::make_shared<Token>(111);
  cout << "Added this token to the list\n";
  tm.AddToken(token);
  auto m = tm.AddToken(222);
  cout << "Changed this token's value to 333 :)\n";
  token->value = 333;
  tm.Revert(m);

  ASSERT_EQ(2, tm.tokens.size())
      << "At this point, token machine should have exactly "
      << "two tokens, you got " << tm.tokens.size();

  ASSERT_EQ(111, tm.tokens[0]->value)
      << "You got the token value wrong here. "
      << "Hint: did you init the memento by-value?";
}

}  // namespace