#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Memento {
 private:
  // This is marked as private so the value can never be changed once object is
  // created.
  int balance_;

 public:
  Memento(int balance) : balance_(balance) {}
  friend class BankAccount;
  friend class BankAccountWithMemento;
};

class BankAccount {
 private:
  int balance_ = 0;

 public:
  explicit BankAccount(const int balance) : balance_(balance) {}

  Memento Deposit(int amount) {
    balance_ += amount;
    return {balance_};
  }

  void Restore(const Memento& m) { balance_ = m.balance_; }

  friend std::ostream& operator<<(std::ostream& os, const BankAccount& obj) {
    return os << "balance: " << obj.balance_;
  }
};

class BankAccountWithMemento  // supports undo/redo
{
 private:
  int balance_ = 0;
  std::vector<std::shared_ptr<Memento>> changes;
  int change_count_;

 public:
  explicit BankAccountWithMemento(const int balance) : balance_(balance) {
    changes.emplace_back(std::make_shared<Memento>(balance));
    change_count_ = 0;
  }

  std::shared_ptr<Memento> Deposit(int amount) {
    balance_ += amount;
    auto m = std::make_shared<Memento>(balance_);
    changes.push_back(m);
    ++change_count_;
    return m;
  }

  void Restore(const std::shared_ptr<Memento>& m) {
    if (m) {
      balance_ = m->balance_;
      changes.push_back(m);
      change_count_ = changes.size() - 1;
    }
  }

  std::shared_ptr<Memento> Undo() {
    if (change_count_ > 0) {
      --change_count_;
      auto m = changes[change_count_];
      balance_ = m->balance_;
      return m;
    }
    return {};
  }

  std::shared_ptr<Memento> Redo() {
    if (change_count_ + 1 < changes.size()) {
      ++change_count_;
      auto m = changes[change_count_];
      balance_ = m->balance_;
      return m;
    }
    return {};
  }

  friend std::ostream& operator<<(std::ostream& os,
                                  const BankAccountWithMemento& obj) {
    return os << "balance: " << obj.balance_;
  }
};
