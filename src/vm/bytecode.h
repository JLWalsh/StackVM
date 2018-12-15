#ifndef BYTECODE_H
#define BYTECODE_H

#include "type.h"
#include "vm.h"

OPCODE   bytecode_program_read_opcode(VM* vm);
INTEGER  bytecode_program_read_int(VM* vm);
UINTEGER bytecode_program_read_uint(VM* vm);
LONG     bytecode_program_read_long(VM* vm);
ULONG    bytecode_program_read_ulong(VM* vm);
POINTER  bytecode_program_read_ptr(VM* vm);
float    bytecode_program_read_float(VM* vm);

OPCODE   bytecode_read_opcode(STREAM* stream);
INTEGER  bytecode_read_int(STREAM* stream);
UINTEGER bytecode_read_uint(STREAM* stream);
LONG     bytecode_read_long(STREAM* stream);
ULONG    bytecode_read_ulong(STREAM* stream);
POINTER  bytecode_read_ptr(STREAM* stream);
float    bytecode_read_float(STREAM* stream);

#endif /* BYTECODE_H */
