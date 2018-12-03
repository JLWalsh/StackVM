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

    NUM_OF_OPCODES
};

#endif /* OPCODE_H */
