#ifndef VM_H
#define VM_H

#include <stdint.h>
#include "stack.h"
#include "executor.h"

typedef struct VM_T
{
  uint64_t    *instruction_ptr;
  uint64_t    *program;
  STACK       stack;
  EXECUTOR    executors[256];
} VM;

VM vm_create(uint64_t* program);

void vm_run(VM *vm);

#endif /* VM_H */
