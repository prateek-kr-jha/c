### Object and Variables:
- An object is used to store a value in memory. A variable is an object that has a name (identifier).
- In general programming, the term object typically refers to an unnamed object in memory, a variable, or a function. In C++, the term object has a narrower definition that excludes functions.
- Initialized = The object is given a known value at the point of definition.
- Assignment = The object is given a known value beyond the point of definition.
- Uninitialized = The object has not been given a known value yet.

### Literals and Operators:
- A literal (also known as a literal constant) is a fixed value that has been inserted directly into the source code.
- The number of operands that an operator takes as input is called the operator’s arity e.g,
uniary, binary, ternanry and nullary.
- Both operator= and operator<< (when used to output values to the console) return their left operand.
Thus, x = 5 returns x, and std::cout << 5 returns std::cout. This is done so that these operators can be chained.


### I/O:
- The C++ I/O library does not provide a way to accept keyboard input without the user having to press enter.
If this is something you desire, you’ll have to use a third party library. For console applications, we’d recommend pdcurses, FXTUI, cpp-terminal, or notcurses. Many graphical user interface libraries have their own functions to do this kind of thing.


### Functions:
- A function is a reusable sequence of statements designed to do a particular job.
```
returnType functionName() // This is the function header (tells the compiler about the existence of the function)
{
    // This is the function body (tells the compiler what the function does)
}
```
- A function parameter is a variable used in the header of a function.
Function parameters work almost identically to variables defined inside the function,
but with one difference: they are initialized with a value provided by the caller of the function.
- When a function is called, all of the parameters of the function are created as variables,
and the value of each of the arguments is copied into the matching parameter (using copy initialization).
This process is called pass by value. Function parameters that utilize pass by value are called value parameters.
- A temporary object (also sometimes called an anonymous object) is an unnamed object that is created by the compiler to store a value temporarily.
- Temporary objects are destroyed at the end of the full expression in which they are created.


### Multi file project:
- When you compile your program, you’ll need to include all of the relevant code files on the compile line.
For example: g++ main.cpp add.cpp -o main, where main.cpp and add.cpp are the names of your code files, and main is the name of the output file.

### Namespaces:
Any names declared inside the namespace won’t be mistaken for identical names in other scopes.
- Only declarations and definitions can appear in the scope of a namespace (not executable statements).
However, a function can be defined inside a namespace, and that function can contain executable statements.

````
#include <iostream> // imports the declaration of std::cout into the global scope

// All of the following statements are part of the global namespace

void foo();    // okay: function forward declaration
int x;         // compiles but strongly discouraged: non-const global variable definition (without initializer)
int y { 5 };   // compiles but strongly discouraged: non-const global variable definition (with initializer)
x = 5;         // compile error: executable statements are not allowed in namespaces

int main()     // okay: function definition
{
    return 0;
}

void goo();    // okay: A function forward declaration
````

### Macros:
a macro is a rule that defines how input text is converted into replacement output text.
- There are two basic types of macros: object-like macros, and function-like macros. function like macro = bad.
- By convention, macro names are typically all upper-case, separated by underscores.
- Avoid macros with substitution text unless no viable alternatives exist.

#### conditional Compilation:
- #ifdef: The #ifdef preprocessor directive allows the preprocessor to check whether an identifier has been previously defined via #define. If so, the code between the #ifdef and matching #endif is compiled. If not, the code is ignored.
```
#include <iostream>

#define PRINT_JOE

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

    return 0;
}
```
- #ifndef: is the opposite of #ifdef, in that it allows you to check whether an identifier has NOT been #defined yet.

- #endif:

### Header:
- Header files allow us to put declarations in one place and then import them wherever we need them. This can save a lot of typing in multi-file programs.
- In C++, it is a best practice for code files to #include their paired header file (if one exists). In the example above, add.cpp includes add.h.

e.g,
```
int something(int); // return type of forward declaration is int
```

```
#include "something.h"

void something(int) // error: wrong return type
{
}
```

- To maximize the chance that missing includes will be flagged by compiler, order your #includes as follows:

  - The paired header file
  - Other headers from your project
  - 3rd party library headers
  - Standard library headers
The headers for each grouping should be sorted alphabetically (unless the documentation for a 3rd party library instructs you to do otherwise).

- Although the preprocessor will happily do so, you should generally not #include .cpp files
  - Doing so can cause naming collisions between source files.
  - In a large project it can be hard to avoid one definition rules (ODR) issues.
  - Any change to such a .cpp file will cause both the .cpp file and any other .cpp file that includes it to recompile, which can take a long time. Headers tend to change less often than source files.
  - It is non-conventional to do so.


- setting include directory for compiler: Using g++, you can use the -I option to specify an alternate include directory:
g++ -o main -I/source/includes main.cpp

#### Header guard:
- All of your header files should have header guards on them. SOME_UNIQUE_NAME_HERE can be any name you want, but by convention is set to the full filename of the header file, typed in all caps, using underscores for spaces or punctuation.
Some good suggestions are a naming convention of PROJECT_PATH_FILE_H, FILE_LARGE-RANDOM-NUMBER_H, or FILE_CREATION-DATE_H.
```
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

// your declarations (and certain types of definitions) here

#endif
```
- #pragma, alternate form of header guards
