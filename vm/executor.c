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
    INTEGER position = state.frame_offset + offset;
    OBJECT  o        = stack_at(stack, position);
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
    INTEGER fun_addr = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));
    INTEGER num_args = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));

    POINTER return_addr = (POINTER)stream_position(program);

    state.instruction_ptr = state.program_start_ptr + fun_addr * sizeof(char);
    state.frame_offset    = stack_position(stack) - num_args;

    stack_push(stack, object_of_int(num_args));
    stack_push(stack, object_of_ptr(return_addr));
    stack_push(stack, object_of_ptr(state.frame_offset));

    return state;
}

STATE op_return(STACK* stack, STREAM* program, STATE state)
{
    OBJECT return_val     = stack_pop(stack);
    state.frame_offset    = stack_pop(stack).int_val;
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

// String operations
STATE op_spush(STACK* stack, STREAM* program, STATE vm)
{
    INTEGER str_pos = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));
}

// Integer operations
STATE op_ipush(STACK* stack, STREAM* program, STATE vm)
{
    INTEGER value = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));

    stack_push(stack, object_of_int(value));

    vm.instruction_ptr = stream_position(program);

    return vm;
}

STATE op_iadd(STACK* stack, STREAM* program, STATE vm)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a + b));

    return vm;
}

STATE op_isub(STACK* stack, STREAM* program, STATE vm)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a - b));

    return vm;
}

STATE op_imul(STACK* stack, STREAM* program, STATE vm)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a * b));
    // TODO check for overflow
    return vm;
}

STATE op_idiv(STACK* stack, STREAM* program, STATE vm)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a / b));
    // TODO check for b = 0
    return vm;
}

STATE op_iand(STACK* stack, STREAM* program, STATE vm)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a & b));

    return vm;
}

STATE op_inot(STACK* stack, STREAM* program, STATE vm)
{
    INTEGER a = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(~a));

    return vm;
}

STATE op_ixor(STACK* stack, STREAM* program, STATE vm)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a ^ b));

    return vm;
}

STATE op_ior(STACK* stack, STREAM* program, STATE vm)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a | b));

    return vm;
}
