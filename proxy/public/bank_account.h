#pragma once

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

using std::ostream;

class BankAccount {
 public:
  virtual ~BankAccount() = default;
  virtual void Deposit(int amount) = 0;
  virtual void Withdraw(int amount) = 0;
};

class CurrentAccount : public BankAccount  // checking
{
 public:
  explicit CurrentAccount(const int balance) : balance(balance) {}

  void Deposit(int amount) override { balance += amount; }

  void Withdraw(int amount) override {
    if (amount <= balance)
      balance -= amount;
  }

  friend ostream& operator<<(ostream& os, const CurrentAccount& obj) {
    return os << "balance: " << obj.balance;
  }

 private:
  int balance;
};