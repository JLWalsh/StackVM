#include "vm.h"
#include "executor.h"
#include <stdio.h>

VM vm_create(STREAM* program)
{
    STACK stack = stack_create(10);

    VM vm;
    vm.stack   = stack;
    vm.program = program;

    POINTER initial_pos = stream_position(program);
    vm.state            = state_create(initial_pos, &stack);

    vm.executors[OP_PUSH]    = op_push;
    vm.executors[OP_LOADARG] = op_loadarg;
    vm.executors[OP_ADD]     = op_add;
    vm.executors[OP_CALL]    = op_call;
    vm.executors[OP_RETURN]  = op_return;
    vm.executors[OP_HALT]    = op_halt;
    vm.executors[OP_PRINT]   = op_print;

    vm.executors[OP_I_PUSH] = op_ipush;
    vm.executors[OP_I_ADD]  = op_iadd;
    vm.executors[OP_I_SUB]  = op_isub;
    vm.executors[OP_I_MUL]  = op_imul;
    vm.executors[OP_I_DIV]  = op_idiv;
    vm.executors[OP_I_AND]  = op_iand;
    vm.executors[OP_I_NOT]  = op_inot;
    vm.executors[OP_I_XOR]  = op_ixor;
    vm.executors[OP_I_OR]   = op_ior;

    return vm;
}

void vm_run(VM* vm)
{
    while (vm->state.running) {
        stream_seek(vm->program, vm->state.instruction_ptr);

        OPCODE opcode = *((OPCODE*)stream_advance(vm->program, sizeof(OPCODE)));

        vm->state.instruction_ptr += sizeof(OPCODE);
        vm->state = vm->executors[opcode](&vm->stack, vm->program, vm->state);
    }
}

void vm_free(VM vm)
{
    stack_free(vm.stack);
}