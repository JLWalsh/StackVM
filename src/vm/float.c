#include "float.h"
#include "bytecode.h"
#include <stdio.h>

STATE op_fpush(VM* vm)
{
    float float_val = bytecode_read_float(program);

    stack_push(stack, object_of_float(float_val));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_fadd(VM* vm)
{
    float a = stack_pop(stack).float_val;
    float b = stack_pop(stack).float_val;

    stack_push(stack, object_of_float(a + b));

    return state;
}

STATE op_fsub(VM* vm)
{
    float a = stack_pop(stack).float_val;
    float b = stack_pop(stack).float_val;

    stack_push(stack, object_of_float(a - b));

    return state;
}

STATE op_fdiv(VM* vm)
{
    float a = stack_pop(stack).float_val;
    float b = stack_pop(stack).float_val;

    stack_push(stack, object_of_float(a / b)); // TODO check for division by zero

    return state;
}

STATE op_fmul(VM* vm)
{
    float a = stack_pop(stack).float_val;
    float b = stack_pop(stack).float_val;

    stack_push(stack, object_of_float(a * b));

    return state;
}

STATE op_fprint(VM* vm)
{
    float a = stack_pop(stack).float_val;

    printf("%f", a);

    return state;
}