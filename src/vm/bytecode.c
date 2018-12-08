#include "bytecode.h"
#include "math.h"

OPCODE bytecode_read_opcode(VM* vm)
{
    OPCODE value              = *((OPCODE*)stream_advance(&vm->program, sizeof(OPCODE)));
    vm->state.instruction_ptr = stream_position(&vm->program);

#ifdef VM_IS_LITTLE_ENDIAN
    return (OPCODE)math_int16_endian_swap(value);
#else
    return value;
#endif
}

INTEGER bytecode_read_int(VM* vm)
{
    INTEGER value             = *((INTEGER*)stream_advance(&vm->program, sizeof(INTEGER)));
    vm->state.instruction_ptr = stream_position(&vm->program);

#ifdef VM_IS_LITTLE_ENDIAN
    return math_int16_endian_swap(value);
#else
    return value;
#endif
}

UINTEGER bytecode_read_uint(VM* vm)
{
    UINTEGER value            = *((UINTEGER*)stream_advance(&vm->program, sizeof(UINTEGER)));
    vm->state.instruction_ptr = stream_position(&vm->program);

#ifdef VM_IS_LITTLE_ENDIAN
    return (UINTEGER)math_int16_endian_swap(value);
#else
    return value;
#endif
}

LONG bytecode_read_long(VM* vm)
{
    LONG value                = *((LONG*)stream_advance(&vm->program, sizeof(LONG)));
    vm->state.instruction_ptr = stream_position(&vm->program);

#ifdef VM_IS_LITTLE_ENDIAN
    return math_int64_endian_swap(value);
#else
    return value;
#endif
}

ULONG bytecode_read_ulong(VM* vm)
{
    ULONG value               = *((ULONG*)stream_advance(&vm->program, sizeof(ULONG)));
    vm->state.instruction_ptr = stream_position(&vm->program);

#ifdef VM_IS_LITTLE_ENDIAN
    return (ULONG)math_int64_endian_swap(value);
#else
    return value;
#endif
}

POINTER bytecode_read_ptr(VM* vm)
{
    POINTER value             = *((POINTER*)stream_advance(&vm->program, sizeof(POINTER)));
    vm->state.instruction_ptr = stream_position(&vm->program);

#ifdef VM_IS_LITTLE_ENDIAN
    return math_int32_endian_swap(value);
#else
    return value;
#endif
}

float bytecode_read_float(VM* vm)
{
    SERIALIZED_FLOAT serialized_float = *((SERIALIZED_FLOAT*)stream_advance(&vm->program, sizeof(SERIALIZED_FLOAT)));
    vm->state.instruction_ptr         = stream_position(&vm->program);

#ifdef VM_IS_LITTLE_ENDIAN
    serialized_float.raw = math_int32_endian_swap(serialized_float.raw);
#endif

    return serialized_float.value;
}