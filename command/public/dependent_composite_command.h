#pragma once

#include "composite_bank_account_command.h"

class DependentCompositeCommand : public CompositeBankAccountCommand {
 public:
  DependentCompositeCommand(
      const std::initializer_list<BankAccountCommand>& items)
      : CompositeBankAccountCommand(items) {}

  void Call() override {
    bool is_successful = true;
    for (auto& cmd : *this) {
      if (is_successful) {
        cmd.Call();
        is_successful = cmd.is_successful_;
      } else {
        cmd.is_successful_ = false;
      }
    }
  }
};