#ifndef OPCODE_H
#define OPCODE_H

#include <stdint.h>

typedef uint8_t OPCODE;

enum OPCODES {
    OP_PUSH,
    OP_LOADARG,
    OP_ADD,
    OP_CALL,
    OP_RETURN,
    OP_HALT,
    OP_PRINT,

    NUM_OF_OPCODES
};

#endif /* OPCODE_H */
