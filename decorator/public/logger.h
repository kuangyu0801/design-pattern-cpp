#pragma once

#include <functional>
#include <iostream>
#include <string>

class Logger {
 public:
  Logger(const std::function<void()>& func, const std::string& name)
      : func_{func}, name_{name} {}

  void operator()() const {
    std::cout << "Entering " << name_ << std::endl;
    func_();
    std::cout << "Exiting " << name_ << std::endl;
  }

  std::function<void()> func_;
  std::string name_;
};

// Function decorator.
template <typename Func>
class StaticLogger {
 public:
  StaticLogger(const Func& func, const std::string& name)
      : func_{func}, name_{name} {}
  // no input parameter and void return.
  void operator()() const {
    std::cout << "Entering " << name_ << std::endl;
    func_();
    std::cout << "Exiting " << name_ << std::endl;
  }

  Func func_;
  std::string name_;
};

template <typename Func>
StaticLogger<Func> MakeStaticLogger(Func func, const std::string& name) {
  return StaticLogger<Func>{func, name};
}

// need partial specialization for this to work
template <typename T>
struct StaticLoggerArgs;

// return type and argument list
template <typename R, typename... Args>
class StaticLoggerArgs<R(Args...)> {
 public:
  StaticLoggerArgs(std::function<R(Args...)> func, const std::string& name)
      : func{func}, name{name} {}

  R operator()(Args... args) {
    std::cout << "Entering " << name << std::endl;
    R result = func(args...);
    std::cout << "Exiting " << name << std::endl;
    return result;
  }

  std::function<R(Args...)> func;
  std::string name;
};

// Use this utility function to avoid using 
// StaticLoggerArgs<double(double, double)>(Add, "HelloFunction")
template <typename R, typename... Args>
// function pointer.
StaticLoggerArgs<R(Args...)> MakeStaticLoggerArgs(R (*func)(Args...), const std::string& name)
{
  return StaticLoggerArgs<R(Args...)>(
    std::function<R(Args...)>(func), 
    name);
}