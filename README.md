# Stack VM
### A VM written in C
[![Build Status](https://travis-ci.org/JLWalsh/StackVM.svg?branch=master)](https://travis-ci.org/JLWalsh/StackVM)

In short, Stack VM (SVM for short) is a barebones virtual machine written in C. As the name states, it is a stack-based machine. The machine will feature detailed types (i.e not just one type to represent numbers like in JS), native string support, and (hopefully) be lightweight enough to be ported to small embedded devices. 

### To get started
In case you want to try it out or contribute to this project, you will need:

- GNU Make
  - If on Windows, use MinGW32 and be sure to add it to your path
- The GCC compiler
  - It might compile with other compilers, but I have not tried yet!
- Clang-format, because C can get messy :)

### Program structure
StackVM programs can be loaded with constants of any type. This is especially useful for strings, as we will be able to reference them using pointers, instead of storing their value in the stack. **Note that any data between the header and the program is considered to be part of the constants section, and therefore will be loaded into memory.** Here is a rough drawing of the program structure:

| Required? | Byte                       | Length (in bytes) | Description                                      |
|-----------|----------------------------|-------------------|--------------------------------------------------|
| Yes       | 0                          | 4 (uint32_t)      | Program start pointer relative to start of file. |
| Yes       | 4                          | 4 (uint32_t)      | Program end pointer relative to start of file.   |
| No        | 8 to program start pointer | any               | Constant variables, of any size.                 |
| Yes!      | program start pointer      | any               | The program itself.                              |

### To build the project
`make` or `make build`

#### Or in debug
`make build-debug`
