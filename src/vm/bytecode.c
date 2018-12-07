#include "bytecode.h"
#include "math.h"

OPCODE bytecode_read_opcode(STREAM* program)
{
    OPCODE value = *((OPCODE*)stream_advance(program, sizeof(OPCODE)));

#ifdef VM_IS_LITTLE_ENDIAN
    return (OPCODE)math_int16_to_big_endian(value);
#else
    return value;
#endif
}

INTEGER bytecode_read_int(STREAM* program)
{
    INTEGER value = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));

#ifdef VM_IS_LITTLE_ENDIAN
    return math_int16_to_big_endian(value);
#else
    return value;
#endif
}

UINTEGER bytecode_read_uint(STREAM* program)
{
    UINTEGER value = *((UINTEGER*)stream_advance(program, sizeof(UINTEGER)));

#ifdef VM_IS_LITTLE_ENDIAN
    return (UINTEGER)math_int16_to_big_endian(value);
#else
    return value;
#endif
}

LONG bytecode_read_long(STREAM* program)
{
    LONG value = *((LONG*)stream_advance(program, sizeof(LONG)));

#ifdef VM_IS_LITTLE_ENDIAN
    return math_int64_to_big_endian(value);
#else
    return value;
#endif
}

ULONG bytecode_read_ulong(STREAM* program)
{
    ULONG value = *((ULONG*)stream_advance(program, sizeof(ULONG)));

#ifdef VM_IS_LITTLE_ENDIAN
    return (ULONG)math_int64_to_big_endian(value);
#else
    return value;
#endif
}

POINTER bytecode_read_ptr(STREAM* program)
{
    POINTER value = *((POINTER*)stream_advance(program, sizeof(POINTER)));

#ifdef VM_IS_LITTLE_ENDIAN
    return math_int32_to_big_endian(value);
#else
    return value;
#endif
}

float bytecode_read_float(STREAM* program)
{
    // TODO investigate why no endian swap is required on Windows (which is little-endian)
    SERIALIZED_FLOAT serialized_float = *((SERIALIZED_FLOAT*)stream_advance(program, sizeof(SERIALIZED_FLOAT)));

    return serialized_float.value;
}