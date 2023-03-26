#pragma once

#include "bank_account_command.h"

class CompositeBankAccountCommand : public std::vector<BankAccountCommand>,
                                    public Command {
public:
  CompositeBankAccountCommand(const std::initializer_list<value_type> &items)
      : vector<BankAccountCommand>(items) {}

  void Call() const override {
    for (auto &cmd : *this)
      cmd.Call();
  }

  void Undo() const override {
    for (auto &cmd : *this)
      cmd.Undo();
  }
};