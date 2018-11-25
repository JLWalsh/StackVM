#include "vm.h"
#include "executor.h"

VM vm_create(EXECUTABLE executable)
{
    STACK stack = stack_create(10); // TODO find clean way to specify stack size

    VM vm;
    vm.stack   = stack;
    vm.program = executable.program;
    vm.state   = state_create(executable);

    vm.executors[OP_LOADARG] = op_loadarg;
    vm.executors[OP_CALL]    = op_call;
    vm.executors[OP_RETURN]  = op_return;
    vm.executors[OP_HALT]    = op_halt;
    vm.executors[OP_PRINT]   = op_print;

    vm.executors[OP_P_PUSH] = op_ppush;

    vm.executors[OP_I_PUSH] = op_ipush;
    vm.executors[OP_I_ADD]  = op_iadd;

    return vm;
}

INTEGER vm_run(VM* vm)
{
    while (vm->state.running) {
        stream_seek(&vm->program, vm->state.instruction_ptr);

        OPCODE opcode = *((OPCODE*)stream_advance(&vm->program, sizeof(OPCODE)));

        vm->state.instruction_ptr += sizeof(OPCODE);
        vm->state = vm->executors[opcode](&vm->stack, &vm->program, vm->state);
    }

    return vm->state.exit_code;
}

void vm_free(VM vm)
{
    stack_free(vm.stack);
}