#include "vm.h"

VM vm_create(uint64_t* program)
{
  STACK stack = stack_create(10);

  VM vm;
  vm.stack = stack;
  vm.program = program;
  vm.instruction_ptr = program;

  vm.executors[0] = nop_executor;
  vm.executors[1] = push_executor;

  return vm;
}

void vm_run(VM *vm)
{
}
