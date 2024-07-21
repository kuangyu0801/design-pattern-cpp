#pragma once

#include <sstream>
#include <string>

namespace visitor {
namespace exercise {

struct AdditionExpression;
struct MultiplicationExpression;
struct Value;

struct ExpressionVisitor {
  // Visit methods here :)
  virtual void Visit(AdditionExpression& ae) = 0;
  virtual void Visit(MultiplicationExpression& me) = 0;
  virtual void Visit(Value& v) = 0;
};

struct Expression {
  virtual void Accept(ExpressionVisitor& ev) = 0;
};

struct Value : Expression {
  int value;

  Value(int value) : value(value) {}

  void Accept(ExpressionVisitor& ev) { ev.Visit(*this); }
};

struct AdditionExpression : Expression {
  Expression &lhs, &rhs;

  AdditionExpression(Expression& lhs, Expression& rhs) : lhs(lhs), rhs(rhs) {}

  void Accept(ExpressionVisitor& ev) override { ev.Visit(*this); }
};

struct MultiplicationExpression : Expression {
  Expression &lhs, &rhs;

  MultiplicationExpression(Expression& lhs, Expression& rhs)
      : lhs(lhs), rhs(rhs) {}

  void Accept(ExpressionVisitor& ev) override { ev.Visit(*this); }
};

struct ExpressionPrinter : ExpressionVisitor {
  std::ostringstream oss;
  // Visit methods here :)
  void Visit(AdditionExpression& ae) override {
    oss << "(";
    ae.lhs.Accept(*this);
    oss << "+";
    ae.rhs.Accept(*this);
    oss << ")";
  }

  void Visit(MultiplicationExpression& me) override {
    me.lhs.Accept(*this);
    oss << "*";
    me.rhs.Accept(*this);
  }

  void Visit(Value& v) override { oss << v.value; }

  std::string str() const { return oss.str(); }
};

}  // namespace exercise
}  // namespace visitor