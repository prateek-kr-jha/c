### Object and Variables:
- An object is used to store a value in memory. A variable is an object that has a name (identifier).
- In general programming, the term object typically refers to an unnamed object in memory, a variable, or a function. In C++, the term object has a narrower definition that excludes functions.

### I/O:
- The C++ I/O library does not provide a way to accept keyboard input without the user having to press enter.
If this is something you desire, you’ll have to use a third party library. For console applications, we’d recommend pdcurses, FXTUI, cpp-terminal, or notcurses. Many graphical user interface libraries have their own functions to do this kind of thing.
