#include "long.h"
#include "bytecode.h"

STATE op_lpush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG val = bytecode_read_long(program);

    stack_push(stack, object_of_long(val));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_ladd(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a + b));

    return state;
}

STATE op_lsub(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a - b));

    return state;
}

STATE op_ldiv(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a / b));

    return state;
}

STATE op_lmul(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a * b));

    return state;
}

STATE op_land(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a & b));

    return state;
}

STATE op_lor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a | b));

    return state;
}

STATE op_lxor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a ^ b));

    return state;
}

STATE op_lnot(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(~a));

    return state;
}

STATE op_llshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a << b));

    return state;
}

STATE op_lrshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a >> b));

    return state;
}

STATE op_ulpush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG val = bytecode_read_ulong(program);

    stack_push(stack, object_of_ulong(val));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_uladd(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a + b));

    return state;
}

STATE op_ulsub(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a - b));

    return state;
}

STATE op_uldiv(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a / b));

    return state;
}

STATE op_ulmul(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a * b));

    return state;
}

STATE op_uland(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a & b));

    return state;
}

STATE op_ulor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a | b));

    return state;
}

STATE op_ulxor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a ^ b));

    return state;
}

STATE op_ulnot(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(~a));

    return state;
}

STATE op_ullshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a << b));

    return state;
}

STATE op_ulrshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a >> b));

    return state;
}