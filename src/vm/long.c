#include "long.h"
#include "bytecode.h"

void op_lpush(VM* vm)
{
    LONG val = bytecode_read_long(&vm->program);

    stack_push(&vm->stack, object_of_long(val));

    vm->state.instruction_ptr = stream_position(&vm->program);
}

void op_ladd(VM* vm)
{
    LONG a = stack_pop(&vm->stack).long_val;
    LONG b = stack_pop(&vm->stack).long_val;

    stack_push(&vm->stack, object_of_long(a + b));
}

void op_lsub(VM* vm)
{
    LONG a = stack_pop(&vm->stack).long_val;
    LONG b = stack_pop(&vm->stack).long_val;

    stack_push(&vm->stack, object_of_long(a - b));
}

void op_ldiv(VM* vm)
{
    LONG a = stack_pop(&vm->stack).long_val;
    LONG b = stack_pop(&vm->stack).long_val;

    stack_push(&vm->stack, object_of_long(a / b));
}

void op_lmul(VM* vm)
{
    LONG a = stack_pop(&vm->stack).long_val;
    LONG b = stack_pop(&vm->stack).long_val;

    stack_push(&vm->stack, object_of_long(a * b));
}

void op_land(VM* vm)
{
    LONG a = stack_pop(&vm->stack).long_val;
    LONG b = stack_pop(&vm->stack).long_val;

    stack_push(&vm->stack, object_of_long(a & b));
}

void op_lor(VM* vm)
{
    LONG a = stack_pop(&vm->stack).long_val;
    LONG b = stack_pop(&vm->stack).long_val;

    stack_push(&vm->stack, object_of_long(a | b));
}

void op_lxor(VM* vm)
{
    LONG a = stack_pop(&vm->stack).long_val;
    LONG b = stack_pop(&vm->stack).long_val;

    stack_push(&vm->stack, object_of_long(a ^ b));
}

void op_lnot(VM* vm)
{
    LONG a = stack_pop(&vm->stack).long_val;

    stack_push(&vm->stack, object_of_long(~a));
}

void op_llshift(VM* vm)
{
    LONG a = stack_pop(&vm->stack).long_val;
    LONG b = stack_pop(&vm->stack).long_val;

    stack_push(&vm->stack, object_of_long(a << b));
}

void op_lrshift(VM* vm)
{
    LONG a = stack_pop(&vm->stack).long_val;
    LONG b = stack_pop(&vm->stack).long_val;

    stack_push(&vm->stack, object_of_long(a >> b));
}

void op_ulpush(VM* vm)
{
    ULONG val = bytecode_read_ulong(&vm->program);

    stack_push(&vm->stack, object_of_ulong(val));

    vm->state.instruction_ptr = stream_position(&vm->program);
}

void op_uladd(VM* vm)
{
    ULONG a = stack_pop(&vm->stack).ulong_val;
    ULONG b = stack_pop(&vm->stack).ulong_val;

    stack_push(&vm->stack, object_of_ulong(a + b));
}

void op_ulsub(VM* vm)
{
    ULONG a = stack_pop(&vm->stack).ulong_val;
    ULONG b = stack_pop(&vm->stack).ulong_val;

    stack_push(&vm->stack, object_of_ulong(a - b));
}

void op_uldiv(VM* vm)
{
    ULONG a = stack_pop(&vm->stack).ulong_val;
    ULONG b = stack_pop(&vm->stack).ulong_val;

    stack_push(&vm->stack, object_of_ulong(a / b));
}

void op_ulmul(VM* vm)
{
    ULONG a = stack_pop(&vm->stack).ulong_val;
    ULONG b = stack_pop(&vm->stack).ulong_val;

    stack_push(&vm->stack, object_of_ulong(a * b));
}

void op_uland(VM* vm)
{
    ULONG a = stack_pop(&vm->stack).ulong_val;
    ULONG b = stack_pop(&vm->stack).ulong_val;

    stack_push(&vm->stack, object_of_ulong(a & b));
}

void op_ulor(VM* vm)
{
    ULONG a = stack_pop(&vm->stack).ulong_val;
    ULONG b = stack_pop(&vm->stack).ulong_val;

    stack_push(&vm->stack, object_of_ulong(a | b));
}

void op_ulxor(VM* vm)
{
    ULONG a = stack_pop(&vm->stack).ulong_val;
    ULONG b = stack_pop(&vm->stack).ulong_val;

    stack_push(&vm->stack, object_of_ulong(a ^ b));
}

void op_ulnot(VM* vm)
{
    ULONG a = stack_pop(&vm->stack).ulong_val;

    stack_push(&vm->stack, object_of_ulong(~a));
}

void op_ullshift(VM* vm)
{
    ULONG a = stack_pop(&vm->stack).ulong_val;
    ULONG b = stack_pop(&vm->stack).ulong_val;

    stack_push(&vm->stack, object_of_ulong(a << b));
}

void op_ulrshift(VM* vm)
{
    ULONG a = stack_pop(&vm->stack).ulong_val;
    ULONG b = stack_pop(&vm->stack).ulong_val;

    stack_push(&vm->stack, object_of_ulong(a >> b));
}