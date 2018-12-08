#ifndef VM_H
#define VM_H

#include "executable.h"
#include "heap.h"
#include "opcode.h"
#include "stack.h"
#include "state.h"

typedef struct VM_T VM;

typedef void (*EXECUTOR)(VM* vm);

struct VM_T {
    STATE    state;
    STREAM   program;
    HEAP     heap;
    STACK    stack;
    EXECUTOR executors[NUM_OF_OPCODES];
};

VM vm_create(EXECUTABLE executable);

INTEGER vm_run(VM* vm);

void vm_sync(VM* vm); // TODO implement this: sync the instruction pointer with the program stream

void vm_free(VM vm);

#endif /* VM_H */
