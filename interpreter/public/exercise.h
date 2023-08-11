
#pragma once

#include <map>
#include <string>

class ExpressionProcessor {
 public:
  int Calculate(const std::string& expression);
  std::map<char, int> variables;
};