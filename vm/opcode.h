#ifndef OPCODE_H
#define OPCODE_H

#include <stdint.h>

typedef uint16_t OPCODE;

enum OPCODES {
    // Control-flow operations
    OP_JMP, // Jump to
    OP_JLE, // Jump if less equal
    OP_JL, // Jump if less
    OP_JGE, // Jump if greater equal
    OP_JG, // Jump if greater
    OP_JE, // Jump if equal
    OP_JNE, // Jump if not equal
    OP_CALL, // Call subroutine
    OP_RET, // Return from subroutine with return value (function)
    OP_RET_VOID, // Return from subroutine with nothing (void)

    // String operations
    OP_S_LEN, // String length
    OP_S_CAT, // Concatenate two strings

    // Memory operations
    OP_GLOAD, // Load from memory
    OP_GSTORE, // Store to memory
    OP_LOAD, // Load from local (frame) memory
    OP_STORE, // Store to local (frame) memory

    // Other operations
    OP_HALT, // Halt the machine
    OP_NOP, // Do nothing

    // Stack operations
    OP_PUSH, // Push to stack
    OP_POP, // Pop stack

    // Integer operations

    OP_I_ADD,
    OP_I_SUB,
    OP_I_MUL,
    OP_I_DIV,
    OP_I_NEG,
    OP_I_REM, // remainder

    OP_I_AND,
    OP_I_OR,
    OP_I_LSHIFT,
    OP_I_RSHIFT,
    OP_I_NOT,
    OP_I_XOR,

    OP_I_TOL,
    OP_I_TOF,
    OP_I_TOD,

    OP_I_CMP,

    // Long operations

    OP_L_ADD,
    OP_L_SUB,
    OP_L_MUL,
    OP_L_DIV,
    OP_L_NEG,
    OP_L_REM, // remainder

    OP_L_AND,
    OP_L_OR,
    OP_L_LSHIFT,
    OP_L_RSHIFT,
    OP_L_NOT,
    OP_L_XOR,

    OP_L_TOI,
    OP_L_TOF,
    OP_L_TOD,

    OP_L_CMP,

    // Float operations

    OP_F_ADD,
    OP_F_SUB,
    OP_F_MUL,
    OP_F_DIV,
    OP_F_NEG,
    OP_F_REM, // remainder

    OP_F_TOI,
    OP_F_TOL,
    OP_F_TOD,

    OP_F_CMP,

    // Double operations

    OP_D_ADD,
    OP_D_SUB,
    OP_D_MUL,
    OP_D_DIV,
    OP_D_NEG,
    OP_D_REM, // remainder

    OP_D_TOI,
    OP_D_TOL,
    OP_D_TOF,

    OP_D_CMP,

    // Pointer operations
    OP_P_CMP,
    OP_P_NULL_CMP, // Compare against null
}

#endif /* OPCODE_H */
