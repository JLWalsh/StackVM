#include "objectbytecode.h"
#include "bytecode.h"

OBJECT_BYTECODE_HEADER object_bytecode_read_header(STREAM* bytecode)
{
    ULONG    bytecode_size = bytecode_read_ulong(bytecode);
    UINTEGER object_id     = bytecode_read_uint(bytecode);

    OBJECT_BYTECODE_HEADER header;
    header.bytecode_size = bytecode_size;
    header.object_id     = object_id;

    return header;
}

OBJECT_BYTECODE_FUNC_TABLE_HEADER object_bytecode_func_table_read_header(STREAM* bytecode)
{
    ULONG table_size = bytecode_read_ulong(bytecode);

    OBJECT_BYTECODE_FUNC_TABLE_HEADER header;
    header.table_size = table_size;

    return header;
}

OBJECT_BYTECODE_INTERFACE_IMPLEMENTATION_HEADER object_bytecode_read_interface_implementation_header(STREAM* bytecode)
{
    UINTEGER interface_id = bytecode_read_uint(bytecode);

    OBJECT_BYTECODE_INTERFACE_IMPLEMENTATION_HEADER header;
    header.interface_id = interface_id;

    return header;
}