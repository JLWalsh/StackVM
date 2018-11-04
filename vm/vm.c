#include "vm.h"
#include "opcode.h"
#include <stdio.h>

VM vm_create(STREAM* program)
{
    STACK stack = stack_create(10);

    VM vm;
    vm.stack           = stack;
    vm.program         = program;
    vm.instruction_ptr = stream_peek(program);

    vm.executors[0] = nop_executor;
    vm.executors[1] = push_executor;
    vm.executors[2] = pop_executor;
    vm.executors[3] = halt_executor;

    return vm;
}

void vm_run(VM* vm)
{
    while (vm->instruction_ptr != NULL) {
        stream_seek(vm->program, vm->instruction_ptr);

        OPCODE opcode = *((OPCODE*)stream_advance(vm->program, sizeof(OPCODE)));

        vm->instruction_ptr = vm->executors[opcode](&vm->stack, vm->instruction_ptr, vm->program);
    }
}
