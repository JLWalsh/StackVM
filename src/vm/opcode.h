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

    NUM_OF_OPCODES
};

#endif /* OPCODE_H */
