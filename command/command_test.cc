#include "gtest/gtest.h"
#include "public/bank_account.h"
#include "public/bank_account_command.h"
#include "public/composite_bank_account_command.h"
#include "public/money_transfer_command.h"
#include "public/dependent_composite_command.h"

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


TEST(CommandPattern, MoneyTransfer) {
  BankAccount receiver;
  BankAccount sender; 
  sender.Deposit(100);
  MoneyTransferCommand cmd(sender, receiver, 50);

  EXPECT_EQ(sender.balance_, 100);
  EXPECT_EQ(receiver.balance_, 0);
  cmd.Call();  
  EXPECT_EQ(sender.balance_, 50);
  EXPECT_EQ(receiver.balance_, 50);

  cmd.Undo();
  EXPECT_EQ(sender.balance_, 100);
  EXPECT_EQ(receiver.balance_, 0);
}

TEST(CommandPattern, MoneyTransferOverLimit) {
  BankAccount receiver;
  BankAccount sender; 
  sender.Deposit(100);
  MoneyTransferCommand cmd(sender, receiver, 5000);

  EXPECT_EQ(sender.balance_, 100);
  EXPECT_EQ(receiver.balance_, 0);
  cmd.Call();  
  EXPECT_EQ(sender.balance_, 100);
  EXPECT_EQ(receiver.balance_, 0);
}
