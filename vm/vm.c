#include "vm.h"
#include "executor.h"
#include <stdio.h>

VM vm_create(STREAM* program)
{
    STACK stack = stack_create(10);

    VM vm;
    vm.stack   = stack;
    vm.program = program;

    char* initial_pos = stream_position(program);
    vm.state          = state_create(initial_pos, initial_pos);

    vm.executors[OP_PUSH]    = op_push;
    vm.executors[OP_LOADARG] = op_loadarg;
    vm.executors[OP_CALL]    = op_call;
    vm.executors[OP_RETURN]  = op_return;
    vm.executors[OP_HALT]    = op_halt;
    vm.executors[OP_PRINT]   = op_print;

    return vm;
}

void vm_run(VM* vm)
{
    while (vm->state.instruction_ptr != NULL) {
        stream_seek(vm->program, vm->state.instruction_ptr);

        OPCODE opcode = *((OPCODE*)stream_advance(vm->program, sizeof(OPCODE)));

        vm->state.instruction_ptr += sizeof(OPCODE);
        vm->state = vm->executors[opcode](&vm->stack, vm->program, vm->state);
    }
}
