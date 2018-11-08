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
    INTEGER offset   = stack_pop(stack).int_val;
    POINTER position = (POINTER)state.frame_ptr + offset;

    OBJECT o = stack_at(stack, position);

    stack_push(stack, o);

    return state;
}

STATE op_call(STACK* stack, STREAM* program, STATE state)
{
    POINTER return_addr = (POINTER)state.instruction_ptr;
    POINTER fp_addr     = (POINTER)state.frame_ptr;

    INTEGER num_args = stack_pop(stack).int_val;
    POINTER fun_addr = stack_pop(stack).ptr_val;

    state.instruction_ptr = (char*)fun_addr;
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