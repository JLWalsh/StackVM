#include "float.h"
#include "bytecode.h"
#include <stdio.h>

STATE op_fpush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    float float_val = bytecode_read_float(program);

    stack_push(stack, object_of_float(float_val));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_fadd(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    float a = stack_pop(stack).float_val;
    float b = stack_pop(stack).float_val;

    stack_push(stack, object_of_float(a + b));

    return state;
}

STATE op_fsub(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    float a = stack_pop(stack).float_val;
    float b = stack_pop(stack).float_val;

    stack_push(stack, object_of_float(a - b));

    return state;
}

STATE op_fdiv(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    float a = stack_pop(stack).float_val;
    float b = stack_pop(stack).float_val;

    stack_push(stack, object_of_float(a / b)); // TODO check for division by zero

    return state;
}

STATE op_fmul(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    float a = stack_pop(stack).float_val;
    float b = stack_pop(stack).float_val;

    stack_push(stack, object_of_float(a * b));

    return state;
}

STATE op_fprint(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    float a = stack_pop(stack).float_val;

    printf("%f", a);

    return state;
}