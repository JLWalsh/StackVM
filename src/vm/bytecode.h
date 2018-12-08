#ifndef BYTECODE_H
#define BYTECODE_H

#include "type.h"
#include "vm.h"

OPCODE   bytecode_read_opcode(VM* vm);
INTEGER  bytecode_read_int(VM* vm);
UINTEGER bytecode_read_uint(VM* vm);
LONG     bytecode_read_long(VM* vm);
ULONG    bytecode_read_ulong(VM* vm);
POINTER  bytecode_read_ptr(VM* vm);
float    bytecode_read_float(VM* vm);

#endif /* BYTECODE_H */
