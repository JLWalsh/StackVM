#include "float.h"
#include "bytecode.h"
#include <stdio.h>

void op_fpush(VM* vm)
{
    float float_val = bytecode_read_float(&vm->program);

    stack_push(&vm->stack, object_of_float(float_val));

    vm->state.instruction_ptr = stream_position(&vm->program);
}

void op_fadd(VM* vm)
{
    float a = stack_pop(&vm->stack).float_val;
    float b = stack_pop(&vm->stack).float_val;

    stack_push(&vm->stack, object_of_float(a + b));
}

void op_fsub(VM* vm)
{
    float a = stack_pop(&vm->stack).float_val;
    float b = stack_pop(&vm->stack).float_val;

    stack_push(&vm->stack, object_of_float(a - b));
}

void op_fdiv(VM* vm)
{
    float a = stack_pop(&vm->stack).float_val;
    float b = stack_pop(&vm->stack).float_val;

    stack_push(&vm->stack, object_of_float(a / b)); // TODO check for division by zero
}

void op_fmul(VM* vm)
{
    float a = stack_pop(&vm->stack).float_val;
    float b = stack_pop(&vm->stack).float_val;

    stack_push(&vm->stack, object_of_float(a * b));
}

void op_fprint(VM* vm)
{
    float a = stack_pop(&vm->stack).float_val;

    printf("%f", a);
}