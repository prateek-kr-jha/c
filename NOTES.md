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

  returnType functionName() // This is the function header (tells the compiler about the existence of the function)
  {
      // This is the function body (tells the compiler what the function does)
  }
