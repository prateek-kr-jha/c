# C++ Pointers & Memory Safety — Command Line Practice Projects

This workbook contains **15 focused command-line C++ projects** designed to build deep understanding of:

* Pointers & references
* Memory layout (stack vs heap)
* Ownership & lifetime
* Undefined behavior (UB)
* Memory safety bugs and fixes

All programs are **terminal-only**, deliberately small, and meant to be **broken, observed, and fixed**.

> Compile everything with:

```
g++ -Wall -Wextra -Werror -fsanitize=address -std=c++17
```

---

## 1. Pointer Playground

### Description

Explore basic pointer concepts interactively.

### Requirements

* Declare variables
* Print value, address, and dereferenced value
* Modify value using pointer

### Scope

**In scope**

* `&` and `*`
* Null pointers

**Out of scope**

* Dynamic allocation

### Data Storage

* Stack variables

### Input / Output

```
Input:
./ptr_playground 10
Output:
Value: 10
Address: 0x7ffee3c
Dereferenced: 10
```

---

## 2. Swap Using Pointer vs Reference

### Description

Compare swapping values using pointers and references.

### Requirements

* Swap using `int*`
* Swap using `int&`

### Data Storage

* Stack variables

### Input / Output

```
Input:
./swap 3 7
Output:
After pointer swap: 7 3
After reference swap: 3 7
```

---

## 3. Dynamic Array Creator

### Description

Create and manage an array on the heap.

### Requirements

* Allocate array using `new[]`
* Fill values
* Deallocate correctly

### Data Storage

* Heap (`new[]` / `delete[]`)

### Input / Output

```
Input:
./dyn_array 5
Output:
Allocated array of size 5
```

---

## 4. String Length Without strlen

### Description

Calculate string length using pointer traversal.

### Requirements

* Accept C-style string
* Traverse until `\0`

### Data Storage

* Stack / read-only memory

### Input / Output

```
Input:
./strlen Hello
Output:
Length: 5
```

---

## 5. Dangling Pointer Demonstrator

### Description

Demonstrate dangling pointer bugs and fixes.

### Requirements

* Return address of local variable (bug)
* Fix using heap allocation

### Data Storage

* Stack (bug)
* Heap (fix)

### Input / Output

```
Input:
./dangling
Output:
Error: Dangling pointer detected
```

---

## 6. Const Correctness Lab

### Description

Explore `const` with pointers.

### Requirements

* Demonstrate:

  * `const int*`
  * `int* const`
  * `const int* const`

### Data Storage

* Stack variables

### Input / Output

```
Input:
./const_demo
Output:
Compilation error explained
```

---

## 7. Shallow vs Deep Copy

### Description

Show difference between shallow and deep copy.

### Requirements

* Class with raw pointer
* Copy constructor bug
* Fix with deep copy

### Data Storage

* Heap memory inside class

### Input / Output

```
Input:
./copy_demo
Output:
Double free detected (before fix)
```

---

## 8. Linked List from Scratch

### Description

Implement singly linked list manually.

### Requirements

* Node struct
* Insert and traverse

### Data Storage

* Heap (nodes)

### Input / Output

```
Input:
./list add 10 add 20
Output:
10 -> 20 -> NULL
```

---

## 9. Function Pointer Menu

### Description

Execute functions using function pointers.

### Requirements

* Menu using function pointers
* No `if-else` chains

### Data Storage

* Function pointer table

### Input / Output

```
Input:
./menu 1
Output:
Addition selected
```

---

## 10. Pointer Arithmetic Visualizer

### Description

Visualize pointer arithmetic behavior.

### Requirements

* Increment pointer
* Print addresses

### Data Storage

* Stack array

### Input / Output

```
Input:
./ptr_math
Output:
ptr+1 moves by sizeof(type)
```

---

## 11. Memory Leak Generator & Fixer

### Description

Intentionally create and fix memory leaks.

### Requirements

* Allocate without delete (bug)
* Fix using RAII

### Data Storage

* Heap

### Input / Output

```
Input:
./leak
Output:
Memory leak detected
```

---

## 12. Reference vs Pointer API Design

### Description

Compare APIs using references vs pointers.

### Requirements

* Nullable pointer API
* Non-null reference API

### Data Storage

* Stack / heap

### Input / Output

```
Input:
./api_design
Output:
Reference safer than pointer
```

---

## 13. Unsafe Cast Demonstrator

### Description

Show dangers of incorrect casts.

### Requirements

* `static_cast`
* `reinterpret_cast`

### Data Storage

* Stack

### Input / Output

```
Input:
./cast_demo
Output:
Undefined behavior example
```

---

## 14. Mini Smart Pointer (Unique Ownership)

### Description

Implement a minimal smart pointer.

### Requirements

* Own a heap object
* Delete in destructor

### Data Storage

* Heap (owned resource)

### Input / Output

```
Input:
./smart_ptr
Output:
Resource released safely
```

---

## 15. Ownership Transfer Preview

### Description

Demonstrate ownership transfer semantics.

### Requirements

* Transfer pointer ownership
* Prevent double delete

### Data Storage

* Heap

### Input / Output

```
Input:
./ownership
Output:
Ownership moved successfully
```

---

## Learning Rules

* Print addresses while learning
* Break code intentionally, then fix it
* Never ignore compiler warnings
* Prefer RAII over raw `new/delete`

## Definition of Done

* No memory leaks under AddressSanitizer
* No undefined behavior
* Clear ownership comments in code
