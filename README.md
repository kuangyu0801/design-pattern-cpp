# design-pattern-cpp

Repo is for practice design pattern in modern C++. 

- course: https://www.udemy.com/course/patterns-cplusplus/

# SOLID design principle

- The SOLID Principles, Explained with Motivational Posters: https://www.globalnerdy.com/2009/07/15/the-solid-principles-explained-with-motivational-posters/

- Principle #1: Single Responsibility Principle (SRP)

Every object should have a single responsibility and that all of its services should be aligned with that responsibility. 
“Responsibility” is defined as “a reason to change”.

- Principle #2: The Open-Closed Principle (OCP)

OCP is about allowing change, but doing it without requiring you to modify existing code.

Classes should be open for extension, and closed for modification.

Once you have a class that works and is being used, you don't want to make changes to it unless you have to. Change is a constant in software development. With OCP, we allow for change through extension rather than through modification of existing code.

- Principle #3: Dependency Inversion Principle (DIP)

High-level modules should not depend on low-level modules. 
Instead, they should both depend on abstractions.

- Principle #4: Interface Segregation Principle(ISP)

If a class exposes so many members that those members can be broken down into
groups that serve different clients that don’t use members from the other groups
, you should think about exposing those member groups as separate interfaces.

larger interfaces should be split into smaller ones. By doing so, we can ensure
that implementing classes only need to be concerned about the methods that are
of interest to them.


Gamma Categorization


# Builder Pattern

The intent of the Builder design pattern is to separate the construction of a complex object from its representation.

Exmaple

![](/docs/images/person_builder_example.png)


# Factory Pattern
Motivation
- Object creation is convoluted
- Constructor is not descriptive
- Object creation (non-piecewise, unlike Builder) cab be outsourced to
  - A separate function
  - A separate class

Factory 
- static method
- separate class with 

# Decorator Pattern
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

Strategy Pattern 的優缺點
Strategy Pattern 的優點是可以讓我們在 runtime 時，自由地去切換需要的 strategy，提供更大的彈性。另外，因為不同的邏輯都各自存放在不同的 strategy class 裡面，所以也更好維護和擴充。

Strategy Pattern vs Template Pattern
Template Pattern 是透過 inheritance 的方式，產生不同的 subclass，來改變一個功能中的某些部分。Strategy Pattern 則是透過 composition 的方式，把不同的 strategy 放到 context 中，來改變一個功能中的某些部分。因此 Template Pattern 的改變是 class 層的變化也是靜態的，而strategy pattern 的改變是 object 層的變化，它是相對動態的，它可以在執行過程中再去改變。

# Proxy vs Decorator
- Proxy: identical interface via inheritance
- Decorator: enhanced interface via aggregate


# State Pattern

![](/docs/images/state_pattern.png)

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


- [ Day 1 ] 我為什麼想學設計模式 ( Design Pattern ): https://ithelp.ithome.com.tw/articles/10201706


# Unit Test

```bazel test --test_output=all //solid_ocp:ocp_test```


# UML Diagram

- https://www.javatpoint.com/uml-class-diagram

# C++ Trivial
C++中换行endl和\n的区别: https://blog.csdn.net/u011675745/article/details/51939094
