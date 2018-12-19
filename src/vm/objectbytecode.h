#ifndef OBJECTBYTECODE_H
#define OBJECTBYTECODE_H

#include "stream.h"
#include "type.h"

typedef struct OBJECT_BYTECODE_HEADER_T {
    ULONG    bytecode_size;
    UINTEGER object_id;
} OBJECT_BYTECODE_HEADER;

typedef struct OBJECT_BYTECODE_FUNC_TABLE_HEADER_T {
    ULONG table_size;
} OBJECT_BYTECODE_FUNC_TABLE_HEADER;

typedef struct OBJECT_BYTECODE_INTERFACE_IMPLEMENTATION_HEADER_T {
    UINTEGER interface_id;
} OBJECT_BYTECODE_INTERFACE_IMPLEMENTATION_HEADER;

OBJECT_BYTECODE_HEADER object_bytecode_read_header(STREAM* bytecode);

OBJECT_BYTECODE_FUNC_TABLE_HEADER object_bytecode_func_table_read_header(STREAM* bytecode);

OBJECT_BYTECODE_INTERFACE_IMPLEMENTATION_HEADER object_bytecode_read_interface_implementation_header(STREAM* bytecode);

#endif /* OBJECTBYTECODE_H */
