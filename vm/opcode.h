#ifndef OPCODE_H
#define OPCODE_H

#include <stdint.h>

typedef uint8_t OPCODE;

enum OPCODES {
    OP_LOADARG,
    OP_CALL,
    OP_RETURN,
    OP_HALT,
    OP_PRINT,

    // STRING
    OP_S_LOAD,

    // INT
    OP_I_LOAD,
    OP_I_PUSH,
    OP_I_ADD,
    OP_I_SUB,
    OP_I_MUL,
    OP_I_DIV,
    OP_I_AND,
    OP_I_NOT,
    OP_I_XOR,
    OP_I_OR,

    NUM_OF_OPCODES
};

#endif /* OPCODE_H */
