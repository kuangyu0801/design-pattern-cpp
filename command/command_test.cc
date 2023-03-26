#include "gtest/gtest.h"
#include "public/bank_account.h"
#include "public/bank_account_command.h"
#include "public/composite_bank_account_command.h"

TEST(CommandPattern, Basic) {
  BankAccount account;

  CompositeBankAccountCommand commands = {
      BankAccountCommand(account, BankAccountCommand::Action::kDeposit, 100),
      BankAccountCommand(account, BankAccountCommand::Action::kWithdraw, 200),
  };

  EXPECT_EQ(account.balance_, 0);
  commands.Call();
  EXPECT_EQ(account.balance_, -100);
  commands.Undo();
  EXPECT_EQ(account.balance_, 0);
}

TEST(CommandPattern, Transfer) { FAIL(); }