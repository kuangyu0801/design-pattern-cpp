#include "public/memento.h"

#include "gtest/gtest.h"

namespace {
using std::cout;
TEST(Memento, ExplicitMemento) {
  BankAccount ba{100};
  auto m1 = ba.Deposit(50);  // 150
  auto m2 = ba.Deposit(25);  // 175
  cout << ba << "\n";

  // undo to m1
  ba.Restore(m1);
  cout << ba << "\n";

  // redo
  ba.Restore(m2);
  cout << ba << "\n";
}

TEST(Memento, SelfContainedMemento) {
  BankAccountWithMemento ba{100};
  ba.Deposit(50);
  ba.Deposit(25);  // 125
  cout << ba << "\n";

  ba.Undo();
  cout << "Undo 1: " << ba << "\n";
  ba.Undo();
  cout << "Undo 2: " << ba << "\n";
  ba.Redo();
  cout << "Redo 2: " << ba << "\n";

  ba.Undo();
  cout << "Undo 2: " << ba << "\n";
}

}  // namespace