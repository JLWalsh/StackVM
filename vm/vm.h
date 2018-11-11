#ifndef VM_H
#define VM_H

#include "executable.h"
#include "executor.h"
#include "opcode.h"
#include "stack.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct VM_T {
    STATE    state;
    STREAM   program;
    STACK    stack;
    EXECUTOR executors[NUM_OF_OPCODES];
} VM;

VM vm_create(EXECUTABLE executable);

INTEGER vm_run(VM* vm);

void vm_free(VM vm);

#endif /* VM_H */
