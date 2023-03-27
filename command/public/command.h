#pragma once

class Command {
 public:
  virtual ~Command() = default;
  virtual void Call() = 0;
  virtual void Undo() = 0;
  bool is_successful_;
};