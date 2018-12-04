# Stack VM
### A VM written in C
[![Build Status](https://travis-ci.org/JLWalsh/StackVM.svg?branch=master)](https://travis-ci.org/JLWalsh/StackVM)

In short, Stack VM (SVM for short) is a barebones virtual machine written in C. As the name states, it is a stack-based machine. The machine will features detailed types (i.e not just one type to represent numbers like in JS), native string support, and (hopefully) be lightweight enough to be ported to small embedded devices. As of now, the SVM is capable of operating on primitives such as integers, and more complex types such as strings. It currently has support for memory allocation operations, but they might be removed in favour of a more object-oriented instruction set that would replace `OP_ALLOC [size]` with something like `OP_NEW [objectid]`. 

### To get started
In case you want to try it out or contribute to this project, you will need:

- CMake
    - So far, the project has been succesfully compiled with MinGW32 and GCC on Linux
- Clang-format, because C can get messy :)

### To build the project solution
```
mkdir solution
cd solution
cmake ..    
```
To generate using a specific generator (i.e MinGW Makefiles, Visual Studio solution, etc), see [the CMake doc on generators](https://cmake.org/cmake/help/v3.13/manual/cmake-generators.7.html?highlight=mingw%20makefiles#id7).
Or use CMake GUI!

### To run tests
After having built the project, from the solution directory:
```
cd test
ctest --verbose
```


### Types
In a near future, all these types will be part of the VM in some way:

| Type             | Size    | Description                                                         |
|------------------|---------|---------------------------------------------------------------------|
| Integer          | 2       | A signed whole number                                               |
| Unsigned integer | 2       | A non-signed whole number                                           |
| Pointer          | 4       | A non-signed whole number capable of representing a memory location |
| Long             | 8       | A signed whole-number                                               |
| Unsigned long    | 8       | A non-signed whole number                                           |
| Float            | ? (TBD) | A high-precision number                                             |
| Byte             | 1       | A group of eight bits                                               |
| Opcode           | 2       | An opcode used only in the bytecode, alias of unsigned integer      |


### Program structure
StackVM programs can be loaded with constants of any type. Constants will be loaded in a special chunk of heap space that is read-only. Constants are especially useful for things like strings, as we can reference them using pointers, instead of storing them directly in the program. **Note that any data between the header and the program is considered to be part of the constants section, and therefore will be loaded into memory.** Here is a rough drawing of the program structure:

| Required? | Byte offset                      | Length (in bytes) | Description                                      |
|-----------|----------------------------|-------------------|--------------------------------------------------|
| Yes       | 0                          | 8 (ULONG)      | File/executable length |
| Yes       | 8                          | 4 (ULONG)      | Constants length   |
| No        | 16                 | Determined by previous entry | Constant values that will be loaded into memory
| Yes!      | After constants      | Determined by `executable length - constants length`               | The program itself!                              |

### To build the project
`make` or `make build`

### Or in debug
`make build-debug`

### To clean the project
`make clean`
