#include "executor.h"
#include "opcode.h"
#include <stdio.h>

STATE op_push(STACK* stack, STREAM* program, STATE state)
{
    INTEGER int_val = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));
    stack_push(stack, object_of_int(int_val));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_loadarg(STACK* stack, STREAM* program, STATE state)
{
    INTEGER offset   = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));
    POINTER position = (POINTER)state.frame_ptr + offset;
    OBJECT  o        = *((OBJECT*)position);
    // OBJECT o = stack_at(stack, position);

    stack_push(stack, o);

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_add(STACK* stack, STREAM* program, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    INTEGER c = a + b;

    stack_push(stack, object_of_int(c));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_call(STACK* stack, STREAM* program, STATE state)
{
    POINTER return_addr = (POINTER)state.instruction_ptr;
    POINTER fp_addr     = (POINTER)state.frame_ptr;

    INTEGER fun_addr = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));
    INTEGER num_args = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));

    state.instruction_ptr = state.program_start_ptr + fun_addr * sizeof(char);
    state.frame_ptr       = (char*)stack_position(stack);

    stack_push(stack, object_of_int(num_args));
    stack_push(stack, object_of_ptr(return_addr));
    stack_push(stack, object_of_ptr(fp_addr));

    // TODO push x times number of local vars

    return state;
}

STATE op_return(STACK* stack, STREAM* program, STATE state)
{
    OBJECT return_val     = stack_pop(stack);
    state.frame_ptr       = (char*)stack_pop(stack).ptr_val;
    state.instruction_ptr = (char*)stack_pop(stack).ptr_val;

    INTEGER num_args = stack_pop(stack).int_val;

    for (int i = 0; i < num_args; i++) {
        stack_pop(stack);
    }

    stack_push(stack, return_val);

    return state;
}

STATE op_halt(STACK* stack, STREAM* program, STATE state)
{
    state.instruction_ptr = NULL;

    return state;
}

STATE op_print(STACK* stack, STREAM* program, STATE state)
{
    OBJECT o = stack_pop(stack);

    printf("%i", o.int_val);

    return state;
}