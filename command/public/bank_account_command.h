#pragma once

#include "bank_account.h"
#include "command.h"

// should really be BankAccountCommand
class BankAccountCommand : public Command {
 public:
  BankAccount& account;
  enum Action { kDeposit, kWithdraw } action;
  int amount_;

  BankAccountCommand(BankAccount& account,
                     const Action action,
                     const int amount)
      : account(account), action(action), amount_(amount) {}

  void Call() const override {
    switch (action) {
      case kDeposit:
        account.Deposit(amount_);
        break;
      case kWithdraw:
        account.Withdraw(amount_);
        break;
      default:
        break;
    }
  }

  void Undo() const override {
    switch (action) {
      case kWithdraw:
        account.Deposit(amount_);
        break;
      case kDeposit:
        account.Withdraw(amount_);
        break;
      default:
        break;
    }
  }
};