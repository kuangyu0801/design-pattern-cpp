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
      : account(account), action(action), amount_(amount) {
    is_successful_ = false;
  }

  void Call() override {
    switch (action) {
      case kDeposit:
        account.Deposit(amount_);
        is_successful_ = true;
        break;
      case kWithdraw:
        is_successful_ = account.Withdraw(amount_);
        break;
      default:
        break;
    }
  }

  void Undo() override {
    switch (action) {
      case kWithdraw:
        account.Deposit(amount_);
        is_successful_ = true;
        break;
      case kDeposit:
        is_successful_ = account.Withdraw(amount_);
        break;
      default:
        break;
    }
  }
};