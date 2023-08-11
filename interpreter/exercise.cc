/**
 *
   "1+2+3"
     ^
*/

#include "public/exercise.h"

#include <cctype>
#include <iostream>
#include <map>
#include <string>

using namespace std;
enum class Operation {
  kPlus,
  kMinus,
};

int ExpressionProcessor::Calculate(const string& expression) {
  size_t i = 0;
  int cur_val = 0;
  int result = 0;
  Operation op = Operation::kPlus;
  while (i < expression.size()) {
    char ch = expression[i];
    if (ch == '+' || ch == '-') {
      result += (op == Operation::kPlus) ? cur_val : -cur_val;
      op = (ch == '+') ? Operation::kPlus : Operation::kMinus;
      cur_val = 0;
    } else if (isdigit(ch)) {
      cur_val = ((ch) - '0') + cur_val * 10;
    } else {
      // single letter variable
      if (i + 1 < expression.size() && isalpha(expression[i + 1])) {
        return 0;
      }
      if (!variables.count(ch)) {
        return 0;
      }
      cur_val = variables[ch] + cur_val * 10;
    }
    i += 1;
  }
  cout << "cur_val: " << cur_val << endl;
  result += (op == Operation::kPlus) ? cur_val : -cur_val;
  return result;
}
