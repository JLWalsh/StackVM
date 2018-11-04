#ifndef VM_H
#define VM_H

#include "executor.h"
#include "stack.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct VM_T {
    char* instruction_ptr;
    STREAM* program;
    STACK stack;
    EXECUTOR executors[256];
} VM;

VM vm_create(STREAM* program);

void vm_run(VM* vm);

#endif /* VM_H */
