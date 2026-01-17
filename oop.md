# C++ Object-Oriented Programming — Command Line Practice Projects

This workbook contains **15 carefully designed command-line C++ projects** to build strong fundamentals in:

* Object-Oriented Programming (OOP)
* Clean class design
* Polymorphism & inheritance
* Operator overloading
* Real-world modeling

All projects are **terminal-only** and intentionally avoid GUIs and frameworks.

---

## 1. User Profile Manager

### Description

A command-line program to manage a user profile using a class-based design.

### Requirements

* Create a user profile (name, age, email)
* Update individual fields
* Display profile information
* Validate age and email format (basic checks)

### Scope

**In scope**

* Class & object
* Encapsulation (private data members)
* Constructors
* Getter / setter methods

**Out of scope**

* Authentication
* File or database persistence

### Data Storage

* In-memory (`UserProfile` object)

### Input / Output

```
Input:
./profile create Prateek 26 prateek@mail.com
Output:
Profile created
```

```
Input:
./profile update age 27
Output:
Age updated
```

```
Input:
./profile show
Output:
Name: Prateek
Age: 27
Email: prateek@mail.com
```

### Guidelines

* Keep all data members private
* Validate inputs inside class methods
* `main()` should only route commands

---

## 2. Bank Account System

### Description

Manage a single bank account from the command line.

### Requirements

* Create account with initial balance
* Deposit money
* Withdraw money
* Show balance

### Scope

**In scope**

* Class & object
* Encapsulation
* Constructors

**Out of scope**

* Multiple accounts
* File/database persistence

### Data Storage

* In-memory (`BankAccount` object)

### Input / Output

```
Input:
./bank create 1000
Output:
Account created with balance 1000
```

```
Input:
./bank withdraw 2000
Output:
Error: Insufficient balance
```

---

## 3. Student Report Card

### Description

Store student marks and calculate grades.

### Requirements

* Accept student name and marks
* Compute average
* Assign grade

### Scope

**In scope**

* `struct` vs `class`
* `enum class` for grades

**Out of scope**

* Ranking system

### Data Storage

* In-memory (`vector<Student>`)

### Input / Output

```
Input:
./report Rahul 70 80 90
Output:
Average: 80
Grade: B
```

---

## 4. Shape Area Calculator

### Description

Calculate area of different shapes using polymorphism.

### Requirements

* Support circle, rectangle, triangle
* Compute area using common interface

### Scope

**In scope**

* Inheritance
* Virtual functions

**Out of scope**

* Perimeter
* 3D shapes

### Data Storage

* In-memory (base-class pointer to derived object)

### Input / Output

```
Input:
./shapes rectangle 5 4
Output:
Area: 20
```

---

## 5. Vehicle Rental System

### Description

Simulate renting vehicles and calculating rent.

### Requirements

* Rent car or bike
* Calculate rent based on hours

### Scope

**In scope**

* Inheritance
* Runtime polymorphism

**Out of scope**

* Discounts
* Billing systems

### Data Storage

* In-memory (`Vehicle*` pointing to derived object)

### Input / Output

```
Input:
./rental bike 3
Output:
Total Rent: 150
```

---

## 6. Library Management (Mini)

### Description

Manage books inside a library.

### Requirements

* Add books
* List books
* Issue books

### Scope

**In scope**

* Composition

**Out of scope**

* User accounts
* File persistence

### Data Storage

* In-memory (`vector<Book>` inside `Library`)

### Input / Output

```
Input:
./library add "Clean Code"
Output:
Book added
```

---

## 7. Command-Line Logger

### Description

Log messages with different severity levels.

### Requirements

* INFO, WARN, ERROR
* Timestamped output

### Scope

**In scope**

* Static members
* Enum class

**Out of scope**

* File logging

### Data Storage

* None (stateless utility)

### Input / Output

```
Input:
./logger error "Disk full"
Output:
[ERROR] Disk full
```

---

## 8. Employee Payroll System

### Description

Calculate salary for different employee types.

### Requirements

* Full-time and contract employees
* Monthly salary calculation

### Scope

**In scope**

* Abstract base class
* Virtual functions

**Out of scope**

* Tax calculations

### Data Storage

* In-memory (`Employee*` polymorphic object)

### Input / Output

```
Input:
./payroll contract 40 500
Output:
Salary: 20000
```

---

## 9. Smart Calculator (Operator Overloading)

### Description

Calculator using operator overloading.

### Requirements

* Overload + - * /

### Scope

**In scope**

* Operator overloading

**Out of scope**

* Expression parsing

### Data Storage

* In-memory (`Number` objects)

### Input / Output

```
Input:
./calc 10 5 +
Output:
15
```

---

## 10. Inventory Management

### Description

Track inventory stock and quantities.

### Requirements

* Add items
* Remove items

### Data Storage

* In-memory (`vector<Item>`)

### Input / Output

```
Input:
./inventory add Pen 10
Output:
Item added
```

---

## 11. File-Based Notes App

### Description

Create and read notes stored in files.

### Requirements

* Write notes
* Read notes

### Data Storage

* File system (`.txt` files)

### Input / Output

```
Input:
./notes write note.txt "Hello World"
Output:
Saved
```

---

## 12. Time & Date Class

### Description

Work with time values and comparisons.

### Requirements

* Add minutes
* Compare times

### Data Storage

* In-memory (`Time` object)

### Input / Output

```
Input:
./time add 10:30 45
Output:
11:15
```

---

## 13. Simple Game (Player vs Monster)

### Description

Turn-based combat simulation.

### Requirements

* Attack
* Health tracking

### Data Storage

* In-memory (`Player`, `Monster` objects)

### Input / Output

```
Input:
./game attack
Output:
Monster HP: 70
```

---

## 14. Command Dispatcher

### Description

Execute commands using polymorphism.

### Requirements

* Register commands
* Execute by name

### Data Storage

* In-memory (`map<string, Command*>`)

### Input / Output

```
Input:
./cmd hello
Output:
Hello World
```

---

## 15. Mini POS Billing Engine

### Description

Simulate a basic POS billing flow.

### Requirements

* Add items
* Generate bill
* Show total

### Data Storage

* In-memory (`vector<Item>` and running total)

### Input / Output

```
Input:
./pos add Burger 120
./pos add Fries 80
./pos bill
Output:
Burger - 120
Fries  - 80
Total: 200
```

---

## Build & Run

```
g++ -Wall -Wextra -std=c++17 main.cpp -o app
./app
```

## Learning Rules

* Keep `main()` thin
* One responsibility per class
* No global mutable state
* Prefer clarity over cleverness
