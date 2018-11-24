#include "executor.h"
#include "opcode.h"
#include "vmstring.h"
#include <stdio.h>

STATE op_loadarg(STACK* stack, STREAM* program, STATE state)
{
    INTEGER offset   = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));
    INTEGER position = state.frame_offset + offset;
    OBJECT  o        = stack_at(stack, position);
    stack_push(stack, o);

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_call(STACK* stack, STREAM* program, STATE state)
{
    POINTER fun_addr = *((POINTER*)stream_advance(program, sizeof(POINTER)));
    INTEGER num_args = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));

    POINTER return_addr = stream_position(program);

    state.instruction_ptr = fun_addr;
    state.frame_offset    = stack_size(stack) - num_args;

    stack_push(stack, object_of_int(num_args));
    stack_push(stack, object_of_ptr(return_addr));
    stack_push(stack, object_of_ptr(state.frame_offset));

    return state;
}

STATE op_return(STACK* stack, STREAM* program, STATE state)
{
    OBJECT return_val     = stack_pop(stack);
    state.frame_offset    = stack_pop(stack).ptr_val;
    state.instruction_ptr = stack_pop(stack).ptr_val;

    INTEGER num_args = stack_pop(stack).int_val;

    for (int i = 0; i < num_args; i++) {
        stack_pop(stack);
    }

    stack_push(stack, return_val);

    return state;
}

STATE op_halt(STACK* stack, STREAM* program, STATE state)
{
    INTEGER exit_code = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));

    state.running   = false;
    state.exit_code = exit_code;

    return state;
}

STATE op_print(STACK* stack, STREAM* program, STATE state)
{
    OBJECT o = stack_pop(stack);

    printf("%i\n", o.int_val);

    return state;
}

// Pointer operations
STATE op_ppush(STACK* stack, STREAM* program, STATE vm)
{
    POINTER pointer = *((POINTER*)stream_advance(program, sizeof(POINTER)));

    stack_push(stack, object_of_ptr(pointer));

    vm.instruction_ptr = stream_position(program);

    return vm;
}