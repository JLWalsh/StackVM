# Stack VM
### A VM written in C

In short, Stack VM (SVM for short) is a barebones virtual machine written in C. As the name states, it is a stack-based machine. The machine will feature detailed types (i.e not just one type to represent numbers like in JS), native string support, and (hopefully) be lightweight enough to be ported to small microcontrollers. 

### To get started
In case you want to try it out or contribute to this project, you will need:

- GNU Make
  - If on Windows, use MinGW32 and be sure to add it to your path
- The GCC compiler
  - It might compile with other compilers, but I have not tried
- Clang-format

### Example program
This is an extremely rudimentary program that prints `Hello world!`.
```assembly
  PUSH "Hello, world!"
  PRINT
```

