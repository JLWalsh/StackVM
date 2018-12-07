#ifndef OPCODE_H
#define OPCODE_H

enum OPCODES {
    OP_LOADARG,
    OP_CALL,
    OP_RETURN,
    OP_HALT,
    OP_PRINT,

    OP_ALLOC,
    OP_DEALLOC,

    // PTR
    OP_P_PUSH,

    // STR
    OP_S_CAT,
    OP_S_PRINT,

    OP_I_PUSH,
    OP_I_ADD,
    OP_I_SUB,
    OP_I_DIV,
    OP_I_MUL,
    OP_I_AND,
    OP_I_OR,
    OP_I_XOR,
    OP_I_NOT,
    OP_I_LSHIFT,
    OP_I_RSHIFT,

    OP_UI_PUSH,
    OP_UI_ADD,
    OP_UI_SUB,
    OP_UI_DIV,
    OP_UI_MUL,
    OP_UI_AND,
    OP_UI_OR,
    OP_UI_XOR,
    OP_UI_NOT,
    OP_UI_LSHIFT,
    OP_UI_RSHIFT,

    OP_L_PUSH,
    OP_L_ADD,
    OP_L_SUB,
    OP_L_DIV,
    OP_L_MUL,
    OP_L_AND,
    OP_L_OR,
    OP_L_XOR,
    OP_L_NOT,
    OP_L_LSHIFT,
    OP_L_RSHIFT,

    OP_UL_PUSH,
    OP_UL_ADD,
    OP_UL_SUB,
    OP_UL_DIV,
    OP_UL_MUL,
    OP_UL_AND,
    OP_UL_OR,
    OP_UL_XOR,
    OP_UL_NOT,
    OP_UL_ULSHIFT,
    OP_UL_RSHIFT,

    OP_F_PUSH,
    OP_F_ADD,
    OP_F_SUB,
    OP_F_DIV,
    OP_F_MUL,

    NUM_OF_OPCODES
};

#endif /* OPCODE_H */
