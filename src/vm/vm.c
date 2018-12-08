#include "vm.h"
#include "bytecode.h"
#include "executor.h"
#include "integer.h"
#include "long.h"
#include "float.h"
#include "vmstring.h"

VM vm_create(EXECUTABLE executable)
{
    VM vm;
    vm.stack   = stack_create(10); // TODO find clean way to specify stack size
    vm.program = executable.program;
    vm.heap    = heap_from(executable.constants, 500); // TODO also applies to heap
    vm.state   = state_create(executable);

    vm.executors[OP_LOADARG] = op_loadarg;
    vm.executors[OP_CALL]    = op_call;
    vm.executors[OP_RETURN]  = op_return;
    vm.executors[OP_HALT]    = op_halt;
    vm.executors[OP_PRINT]   = op_print;

    vm.executors[OP_P_PUSH]  = op_ppush;
    vm.executors[OP_ALLOC]   = op_alloc;
    vm.executors[OP_DEALLOC] = op_dealloc;

    vm.executors[OP_S_CAT]   = op_scat;
    vm.executors[OP_S_PRINT] = op_sprint;

    vm.executors[OP_I_PUSH]   = op_ipush;
    vm.executors[OP_I_ADD]    = op_iadd;
    vm.executors[OP_I_SUB]    = op_isub;
    vm.executors[OP_I_DIV]    = op_idiv;
    vm.executors[OP_I_MUL]    = op_imul;
    vm.executors[OP_I_AND]    = op_iand;
    vm.executors[OP_I_OR]     = op_ior;
    vm.executors[OP_I_XOR]    = op_ixor;
    vm.executors[OP_I_NOT]    = op_inot;
    vm.executors[OP_I_LSHIFT] = op_ilshift;
    vm.executors[OP_I_RSHIFT] = op_irshift;

    vm.executors[OP_UI_PUSH]   = op_uipush;
    vm.executors[OP_UI_ADD]    = op_uiadd;
    vm.executors[OP_UI_SUB]    = op_uisub;
    vm.executors[OP_UI_DIV]    = op_uidiv;
    vm.executors[OP_UI_MUL]    = op_uimul;
    vm.executors[OP_UI_AND]    = op_uiand;
    vm.executors[OP_UI_OR]     = op_uior;
    vm.executors[OP_UI_XOR]    = op_uixor;
    vm.executors[OP_UI_NOT]    = op_uinot;
    vm.executors[OP_UI_LSHIFT] = op_uilshift;
    vm.executors[OP_UI_RSHIFT] = op_uirshift;

    vm.executors[OP_L_PUSH]   = op_lpush;
    vm.executors[OP_L_ADD]    = op_ladd;
    vm.executors[OP_L_SUB]    = op_lsub;
    vm.executors[OP_L_DIV]    = op_ldiv;
    vm.executors[OP_L_MUL]    = op_lmul;
    vm.executors[OP_L_AND]    = op_land;
    vm.executors[OP_L_OR]     = op_lor;
    vm.executors[OP_L_XOR]    = op_lxor;
    vm.executors[OP_L_NOT]    = op_lnot;
    vm.executors[OP_L_LSHIFT] = op_llshift;
    vm.executors[OP_L_RSHIFT] = op_lrshift;

    vm.executors[OP_UL_PUSH]    = op_ulpush;
    vm.executors[OP_UL_ADD]     = op_uladd;
    vm.executors[OP_UL_SUB]     = op_ulsub;
    vm.executors[OP_UL_DIV]     = op_uldiv;
    vm.executors[OP_UL_MUL]     = op_ulmul;
    vm.executors[OP_UL_AND]     = op_uland;
    vm.executors[OP_UL_OR]      = op_ulor;
    vm.executors[OP_UL_XOR]     = op_ulxor;
    vm.executors[OP_UL_NOT]     = op_ulnot;
    vm.executors[OP_UL_ULSHIFT] = op_ullshift;
    vm.executors[OP_UL_RSHIFT]  = op_ulrshift;

    vm.executors[OP_F_PUSH]  = op_fpush;
    vm.executors[OP_F_ADD]   = op_fadd;
    vm.executors[OP_F_SUB]   = op_fsub;
    vm.executors[OP_F_DIV]   = op_fdiv;
    vm.executors[OP_F_MUL]   = op_fmul;
    vm.executors[OP_F_PRINT] = op_fprint;

    // TODO add static assertion to ensure that sizeof(OPCODE) is big enough to fit all upcodes

    return vm;
}

INTEGER vm_run(VM* vm)
{
    while (vm->state.running) {
        stream_seek(&vm->program, vm->state.instruction_ptr);

        OPCODE opcode = bytecode_read_opcode(&vm->program);

        vm->state.instruction_ptr += sizeof(OPCODE);
        vm->state = vm->executors[opcode](&vm->stack, &vm->program, &vm->heap, vm->state);
    }

    return vm->state.exit_code;
}

void vm_free(VM vm)
{
    stack_free(vm.stack);
}