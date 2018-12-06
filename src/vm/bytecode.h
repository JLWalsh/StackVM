#ifndef BYTECODE_H
#define BYTECODE_H

#include "stream.h"
#include "type.h"

OPCODE   bytecode_read_opcode(STREAM* program);
INTEGER  bytecode_read_int(STREAM* program);
UINTEGER bytecode_read_uint(STREAM* program);
LONG     bytecode_read_long(STREAM* program);
ULONG    bytecode_read_ulong(STREAM* program);
POINTER  bytecode_read_ptr(STREAM* program);
float    bytecode_read_float(STREAM* program);

#endif /* BYTECODE_H */
