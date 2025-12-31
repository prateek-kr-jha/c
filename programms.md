
# C++ Practice Programs — Complete Learning Guide (All 15)

This document contains **15 carefully chosen C++ practice programs** designed to
build strong fundamentals, clean coding habits, and real-world engineering thinking.

All programs are **terminal-based by design** to keep the focus on **core C++ concepts**
rather than UI or frameworks.

---

## 1. Calculator

### Description
A command-line calculator that performs arithmetic and geometry operations.

### Requirements
- Accept operands and operator from command line
- Support:
  - Add, Subtract, Multiply, Divide
  - Modulo, Power
  - Area of square, rectangle, circle
- Handle invalid input and division by zero

### Scope
**In scope**
- Functions
- `enum class`
- Exception handling
- Input validation

**Out of scope**
- Expression parsing (`3 + 5 * 2`)
- GUI

### Guidelines
- Use `enum class` for operations
- Throw standard exceptions
- Keep `main()` thin

---

## 2. Unit Converter

### Description
Converts values between different units.

### Requirements
- Convert:
  - km ↔ miles
  - Celsius ↔ Fahrenheit
  - kg ↔ pounds
- Accept input via terminal

### Scope
**In scope**
- Mathematical formulas
- Floating-point precision
- Enums for unit types

**Out of scope**
- File I/O
- GUI

### Guidelines
- Use `constexpr` for conversion constants
- Validate numeric input

---

## 3. Password Strength Checker

### Description
Checks whether a password is weak, medium, or strong.

### Requirements
- Minimum length
- At least one digit
- At least one uppercase letter
- At least one special character

### Scope
**In scope**
- String traversal
- Character classification (`<cctype>`)

**Out of scope**
- Encryption
- Storage

### Guidelines
- Avoid ASCII magic numbers
- Give clear feedback

---

## 4. Number Guessing Game

### Description
User guesses a randomly generated number.

### Requirements
- Generate random number in a range
- Indicate too high / too low
- Count attempts

### Scope
**In scope**
- Loops
- Conditionals
- Random number generation

**Out of scope**
- Persistent storage
- Graphics

### Guidelines
- Use `<random>`
- Validate input

---

## 5. Grade Calculator

### Description
Calculates grades based on marks.

### Requirements
- Accept marks
- Assign grades using ranges
- Reject invalid input

### Scope
**In scope**
- Conditional logic
- Range checks

**Out of scope**
- Multiple students
- File storage

### Guidelines
- Clearly define grade boundaries
- Handle edge values

---

## 6. Simple ATM Simulator

### Description
Simulates basic ATM operations.

### Requirements
- Deposit money
- Withdraw money
- Show balance

### Scope
**In scope**
- State management
- Error handling
- Constants

**Out of scope**
- Real banking APIs
- Authentication

### Guidelines
- Prevent negative balance
- Keep logic separate from I/O

---

## 7. CLI Todo List App

### Description
Manages a list of tasks from the terminal.

### Requirements
- Add tasks
- Delete tasks
- List tasks
- Save tasks to file

### Scope
**In scope**
- Containers (`std::vector`)
- File I/O

**Out of scope**
- Multi-user support
- GUI

### Guidelines
- Separate file logic from core logic
- Use clear task IDs

---

## 8. Student Management System

### Description
Manages student data and basic analytics.

### Requirements
- Add students
- Store marks
- Calculate average and ranking

### Scope
**In scope**
- `struct` vs `class`
- Containers
- Sorting

**Out of scope**
- Database
- UI

### Guidelines
- Keep data models simple
- Avoid global state

---

## 9. Bank Account System

### Description
Simulates multiple bank accounts and transactions.

### Requirements
- Create accounts
- Deposit, withdraw, transfer
- Enforce business rules

### Scope
**In scope**
- Classes and encapsulation
- Invariants
- Exception handling

**Out of scope**
- Networking
- Real payments

### Guidelines
- Never allow invalid state
- Throw exceptions for rule violations

---

## 10. Command Line Argument Parser

### Description
Parses and validates command-line flags.

### Requirements
- Support flags like `--help`, `--verbose`
- Validate combinations
- Print usage

### Scope
**In scope**
- `argc`, `argv`
- String parsing

**Out of scope**
- External libraries

### Guidelines
- Fail fast on invalid input
- Centralize usage text

---

## 11. File-Based Calculator

### Description
Reads expressions from a file and evaluates them.

### Requirements
- Read input from file
- Perform calculations
- Write output

### Scope
**In scope**
- File streams
- Batch processing

**Out of scope**
- Complex parsing
- GUI

### Guidelines
- Handle file errors
- Keep calculation logic reusable

---

## 12. Expression Evaluator

### Description
Evaluates expressions like `3 + 5 * 2`.

### Requirements
- Respect operator precedence
- Support basic arithmetic

### Scope
**In scope**
- Stacks
- Algorithms

**Out of scope**
- Variables
- Parentheses (initially)

### Guidelines
- Keep parsing logic clean
- Validate tokens

---

## 13. Logging System

### Description
Writes log messages to a file with severity levels.

### Requirements
- Levels: INFO, WARN, ERROR
- Timestamp each log
- Append to file

### Scope
**In scope**
- `enum class`
- File output
- Formatting

**Out of scope**
- Log rotation
- Multithreading

### Guidelines
- Centralize logging
- Minimal public API

---

## 14. Library Management System

### Description
Manages books and borrowing records.

### Requirements
- Add books
- Borrow and return books
- Track availability

### Scope
**In scope**
- Object relationships
- State transitions

**Out of scope**
- Databases
- Authentication

### Guidelines
- Prevent invalid state transitions
- Separate logic from I/O

---

## 15. Mini Shell

### Description
Implements a basic command shell.

### Requirements
- Support commands: `help`, `exit`, `cd`
- Continuous input loop

### Scope
**In scope**
- Parsing
- Loop-driven systems
- Command dispatch

**Out of scope**
- Full shell features
- Process management

### Guidelines
- Validate commands
- Keep command handling modular

---

## General Guidelines (Applies to ALL Programs)

- Prefer `enum class` over raw constants
- Prefer `constexpr` over macros
- Catch exceptions by `const std::exception&`
- Keep `main()` thin
- Separate parsing, logic, and execution
- Validate all user input
- Handle edge cases explicitly
- Optimize for clarity before performance

---

## Learning Objective

These programs are designed to help you:
- Master **core C++ concepts**
- Write **safe and maintainable code**
- Think in terms of **design and correctness**
- Prepare for **interviews and real-world projects**

---

### Golden Rule

> Make invalid states impossible to represent.
