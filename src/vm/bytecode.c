#include "bytecode.h"
#include "math.h"

OPCODE bytecode_program_read_opcode(VM* vm)
{
    OPCODE value              = bytecode_read_opcode(&vm->program);
    vm->state.instruction_ptr = stream_position(&vm->program);

    return value;
}

INTEGER bytecode_program_read_int(VM* vm)
{
    INTEGER value             = bytecode_read_int(&vm->program);
    vm->state.instruction_ptr = stream_position(&vm->program);

    return value;
}

UINTEGER bytecode_program_read_uint(VM* vm)
{
    UINTEGER value            = bytecode_read_uint(&vm->program);
    vm->state.instruction_ptr = stream_position(&vm->program);

    return value;
}

LONG bytecode_program_read_long(VM* vm)
{
    LONG value                = bytecode_read_long(&vm->program);
    vm->state.instruction_ptr = stream_position(&vm->program);

    return value;
}

ULONG bytecode_program_read_ulong(VM* vm)
{
    ULONG value               = bytecode_read_ulong(&vm->program);
    vm->state.instruction_ptr = stream_position(&vm->program);

    return value;
}

POINTER bytecode_program_read_ptr(VM* vm)
{
    POINTER value             = bytecode_read_ptr(&vm->program);
    vm->state.instruction_ptr = stream_position(&vm->program);

    return value;
}

float bytecode_program_read_float(VM* vm)
{
    float value               = bytecode_read_float(&vm->program);
    vm->state.instruction_ptr = stream_position(&vm->program);

    return value;
}

OPCODE bytecode_read_opcode(STREAM* stream)
{
    OPCODE value = *((OPCODE*)stream_advance(stream, sizeof(OPCODE)));

#ifdef VM_IS_LITTLE_ENDIAN
    value = (OPCODE)math_int16_endian_swap(value);
#endif

    return value;
}

INTEGER bytecode_read_int(STREAM* stream)
{
    INTEGER value = *((INTEGER*)stream_advance(stream, sizeof(INTEGER)));

#ifdef VM_IS_LITTLE_ENDIAN
    value = (INTEGER)math_int16_endian_swap(value);
#endif

    return value;
}

UINTEGER bytecode_read_uint(STREAM* stream)
{
    UINTEGER value = *((UINTEGER*)stream_advance(stream, sizeof(UINTEGER)));

#ifdef VM_IS_LITTLE_ENDIAN
    value = (UINTEGER)math_int16_endian_swap(value);
#endif

    return value;
}

LONG bytecode_read_long(STREAM* stream)
{
    LONG value = *((LONG*)stream_advance(stream, sizeof(LONG)));

#ifdef VM_IS_LITTLE_ENDIAN
    value = (LONG)math_int64_endian_swap(value);
#endif

    return value;
}

ULONG bytecode_read_ulong(STREAM* stream)
{
    ULONG value = *((ULONG*)stream_advance(stream, sizeof(ULONG)));

#ifdef VM_IS_LITTLE_ENDIAN
    value = (ULONG)math_int64_endian_swap(value);
#endif

    return value;
}

POINTER bytecode_read_ptr(STREAM* stream)
{
    POINTER value = *((POINTER*)stream_advance(stream, sizeof(POINTER)));

#ifdef VM_IS_LITTLE_ENDIAN
    value = (POINTER)math_int64_endian_swap(value);
#endif

    return value;
}

float bytecode_read_float(STREAM* stream)
{
    SERIALIZED_FLOAT serialized_float = *((SERIALIZED_FLOAT*)stream_advance(stream, sizeof(SERIALIZED_FLOAT)));

#ifdef VM_IS_LITTLE_ENDIAN
    serialized_float.raw = math_int32_endian_swap(serialized_float.raw);
#endif

    return serialized_float.value;
}