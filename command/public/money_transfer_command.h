#pragma once

#include "dependent_composite_command.h"

class MoneyTransferCommand : public DependentCompositeCommand {
 public:
  MoneyTransferCommand(BankAccount& sender, BankAccount& receiver, int amount)
      : DependentCompositeCommand({
            BankAccountCommand(
                sender, BankAccountCommand::Action::kWithdraw, amount),
            BankAccountCommand(
                receiver, BankAccountCommand::Action::kDeposit, amount),
        }) {}
};