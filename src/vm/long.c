#include "long.h"
#include "bytecode.h"

STATE op_lpush(VM* vm)
{
    LONG val = bytecode_read_long(program);

    stack_push(stack, object_of_long(val));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_ladd(VM* vm)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a + b));

    return state;
}

STATE op_lsub(VM* vm)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a - b));

    return state;
}

STATE op_ldiv(VM* vm)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a / b));

    return state;
}

STATE op_lmul(VM* vm)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a * b));

    return state;
}

STATE op_land(VM* vm)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a & b));

    return state;
}

STATE op_lor(VM* vm)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a | b));

    return state;
}

STATE op_lxor(VM* vm)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a ^ b));

    return state;
}

STATE op_lnot(VM* vm)
{
    LONG a = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(~a));

    return state;
}

STATE op_llshift(VM* vm)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a << b));

    return state;
}

STATE op_lrshift(VM* vm)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a >> b));

    return state;
}

STATE op_ulpush(VM* vm)
{
    ULONG val = bytecode_read_ulong(program);

    stack_push(stack, object_of_ulong(val));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_uladd(VM* vm)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a + b));

    return state;
}

STATE op_ulsub(VM* vm)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a - b));

    return state;
}

STATE op_uldiv(VM* vm)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a / b));

    return state;
}

STATE op_ulmul(VM* vm)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a * b));

    return state;
}

STATE op_uland(VM* vm)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a & b));

    return state;
}

STATE op_ulor(VM* vm)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a | b));

    return state;
}

STATE op_ulxor(VM* vm)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a ^ b));

    return state;
}

STATE op_ulnot(VM* vm)
{
    ULONG a = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(~a));

    return state;
}

STATE op_ullshift(VM* vm)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a << b));

    return state;
}

STATE op_ulrshift(VM* vm)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a >> b));

    return state;
}