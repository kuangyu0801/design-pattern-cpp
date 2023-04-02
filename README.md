# design-pattern-cpp

Repo is for practice design pattern in modern C++. 

- course: https://www.udemy.com/course/patterns-cplusplus/

# SOLID design principle

- Dependency Inversion Principle (DIP)

-  high-level modules should not depend on low-level modules. Instead, they should both depend on abstractions


Decorator Pattern:
https://www.tutorialspoint.com/design_pattern/decorator_pattern.htm

Decorator pattern allows a user to add new functionality to an existing object without altering its structure. This type of design pattern comes under structural pattern as this pattern acts as a wrapper to existing class.

# Template Pattern
- Template Pattern 的優缺點
- 比較 DRY (Don't Repeat Yourself)
 Template Pattern 也會讓你受制於 base class 所定下的設計，因而失去了一些彈性。另外使用 Template Pattern 的時候，要小心不要為了重用部分的功能，而把不太相關的 class 硬湊在一起，不正確的抽象化常常會讓程式碼變得很難維護。
- https://ithelp.ithome.com.tw/articles/10220163
# Proxy
- preserve the interface
- change the underlying implementation

# Strategy

# Proxy vs Decorator
- Proxy: identical interface via inheritance
- Decorator: enhanced interface via aggregate


# Chain of Responsibiliy


# Command
- command query seperation

BIG PICTURE
Use the Command pattern when you want to execute queue operations, schedule their execution, or execute them remotely.
Imagine a job queue: you add commands to the queue on one end, and on the other end sit a group of threads. Threads run the following script: they remove a command from the queue, call its execute() method, wait for the call to finish, then discard the command object and retrieve a new one.

Use the Command pattern when you want to parameterise objects with operations and you don’t have a common interface.
The Command pattern can turn a specific method call into a stand-alone object. This change opens up a lot of interesting uses: you can pass commands as method arguments, store them inside other objects, switch linked commands at runtime, etc.

https://faun.pub/head-first-design-patterns-using-go-5-encapsulating-invocation-the-command-pattern-2f8c0a79d1c7


# Interpreter

- Textual input to be processed in OOP structure.
- processing structured text data (lexing, parsing)


# Mediator Pattern

The intent of the Mediator Pattern is to reduce the complexity and dependencies between tightly coupled objects communicating directly with one another. This is achieved by creating a mediator object that takes care of the interaction between dependent objects. Consequently, all the communication goes through the mediator.

![](/docs/images/mediator_pattern.png)