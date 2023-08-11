#include "public/parse.h"

#include <string>

#include "public/binary_operation.h"
#include "public/integer.h"
#include "public/token.h"
#include "public/element.h"

using namespace std;

using Type = Token::Type;

unique_ptr<Element> ParseTokens(const vector<Token>& tokens) {
  auto result = make_unique<BinaryOperation>();
  bool have_lhs = false;
  for (size_t i = 0; i < tokens.size(); i++) {
    auto token = tokens[i];
    switch (token.type_) {
      case Type::kInteger:
        // scoped local variable
        {
          int value = stoi(token.text_);
          auto integer = make_shared<Integer>(value);
          if (!have_lhs) {
            result->lhs = integer;
            have_lhs = true;
          } else {
            result->rhs = integer;
          }
        }
        break;
      case Type::kPlus:
        result->type = BinaryOperation::OpType::kAddition;
        break;
      case Type::kMinus:
        result->type = BinaryOperation::OpType::kSubtraction;
        break;
      case Type::kLeftPare:
        // scoped local variable
        {
          int j = i;
          for (; j < tokens.size(); ++j) {
            if (tokens[j].type_ == Type::kRightPare) {
              break;  // found it!
            }
          }
          vector<Token> subexpression(&tokens[i + 1], &tokens[j]);
          // Recursive parsing.
          auto element = ParseTokens(subexpression);
          if (!have_lhs) {
            result->lhs = std::move(element);
            have_lhs = true;
          } else {
            result->rhs = std::move(element);
            i = j;  // advance
          }
        }
        break;
      case Type::kRightPare:
        break;
    }
  }
  return result;
}