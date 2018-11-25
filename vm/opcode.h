#ifndef OPCODE_H
#define OPCODE_H

#include <stdint.h>

enum OPCODES {
    OP_LOADARG,
    OP_CALL,
    OP_RETURN,
    OP_HALT,
    OP_PRINT,

    // PTR
    OP_P_PUSH,

    OP_I_PUSH,
    OP_I_ADD,

    NUM_OF_OPCODES
};

#endif /* OPCODE_H */
