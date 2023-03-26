#pragma once

class Command {
public:
  virtual ~Command() = default;
  virtual void Call() const = 0;
  virtual void Undo() const = 0;
};