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

    vm.executors[OP_JMP]        = op_jmp;
    vm.executors[OP_JLE]        = op_jle;
    vm.executors[OP_JL]         = op_jl;
    vm.executors[OP_JGE]        = op_jge;
    vm.executors[OP_JG]         = op_jg;
    vm.executors[OP_JE]         = op_je;
    vm.executors[OP_JNE]        = op_jne;
    vm.executors[OP_CALL]       = op_call;
    vm.executors[OP_RET]        = op_ret;
    vm.executors[OP_RET_VOID]   = op_retvoid;
    vm.executors[OP_S_LEN]      = op_slen;
    vm.executors[OP_S_CAT]      = op_scat;
    vm.executors[OP_GLOAD]      = op_gload;
    vm.executors[OP_GSTORE]     = op_gstore;
    vm.executors[OP_LOAD]       = op_load;
    vm.executors[OP_STORE]      = op_store;
    vm.executors[OP_HALT]       = op_halt;
    vm.executors[OP_NOP]        = op_n;
    vm.executors[OP_PUSH]       = op_push;
    vm.executors[OP_POP]        = op_p;
    vm.executors[OP_I_ADD]      = op_iadd;
    vm.executors[OP_I_SUB]      = op_isub;
    vm.executors[OP_I_MUL]      = op_imul;
    vm.executors[OP_I_DIV]      = op_idiv;
    vm.executors[OP_I_NEG]      = op_ineg;
    vm.executors[OP_I_REM]      = op_irem;
    vm.executors[OP_I_AND]      = op_iand;
    vm.executors[OP_I_OR]       = op_ior;
    vm.executors[OP_I_LSHIFT]   = op_ilshift;
    vm.executors[OP_I_RSHIFT]   = op_irshift;
    vm.executors[OP_I_NOT]      = op_inot;
    vm.executors[OP_I_XOR]      = op_ixor;
    vm.executors[OP_I_TOL]      = op_itol;
    vm.executors[OP_I_TOF]      = op_itof;
    vm.executors[OP_I_TOD]      = op_itod;
    vm.executors[OP_I_CMP]      = op_icmp;
    vm.executors[OP_L_ADD]      = op_ladd;
    vm.executors[OP_L_SUB]      = op_lsub;
    vm.executors[OP_L_MUL]      = op_lmul;
    vm.executors[OP_L_DIV]      = op_ldiv;
    vm.executors[OP_L_NEG]      = op_lneg;
    vm.executors[OP_L_REM]      = op_lrem;
    vm.executors[OP_L_AND]      = op_land;
    vm.executors[OP_L_OR]       = op_lor;
    vm.executors[OP_L_LSHIFT]   = op_llshift;
    vm.executors[OP_L_RSHIFT]   = op_lrshift;
    vm.executors[OP_L_NOT]      = op_lnot;
    vm.executors[OP_L_XOR]      = op_lxor;
    vm.executors[OP_L_TOI]      = op_ltoi;
    vm.executors[OP_L_TOF]      = op_ltof;
    vm.executors[OP_L_TOD]      = op_ltod;
    vm.executors[OP_L_CMP]      = op_lcmp;
    vm.executors[OP_F_ADD]      = op_fadd;
    vm.executors[OP_F_SUB]      = op_fsub;
    vm.executors[OP_F_MUL]      = op_fmul;
    vm.executors[OP_F_DIV]      = op_fdiv;
    vm.executors[OP_F_NEG]      = op_fneg;
    vm.executors[OP_F_REM]      = op_frem;
    vm.executors[OP_F_TOI]      = op_ftoi;
    vm.executors[OP_F_TOL]      = op_ftol;
    vm.executors[OP_F_TOD]      = op_ftod;
    vm.executors[OP_F_CMP]      = op_fcmp;
    vm.executors[OP_D_ADD]      = op_dadd;
    vm.executors[OP_D_SUB]      = op_dsub;
    vm.executors[OP_D_MUL]      = op_dmul;
    vm.executors[OP_D_DIV]      = op_ddiv;
    vm.executors[OP_D_NEG]      = op_dneg;
    vm.executors[OP_D_REM]      = op_drem;
    vm.executors[OP_D_TOI]      = op_dtoi;
    vm.executors[OP_D_TOL]      = op_dtol;
    vm.executors[OP_D_TOF]      = op_dtof;
    vm.executors[OP_D_CMP]      = op_dcmp;
    vm.executors[OP_P_CMP]      = op_pcmp;
    vm.executors[OP_P_NULL_CMP] = op_pnullcmp;

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
