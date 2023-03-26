#pragma once

#include <iostream>

class BankAccount {
 public:
  int balance_ = 0;
  int overdraft_limit = -500;

  void Deposit(int amount) {
    balance_ += amount;
    std::cout << "deposited " << amount << ", balance_ now " << balance_
              << "\n";
  }

  void Withdraw(int amount) {
    if (balance_ - amount >= overdraft_limit) {
      balance_ -= amount;
      std::cout << "withdrew " << amount << ", balance_ now " << balance_
                << "\n";
    }
  }
};
