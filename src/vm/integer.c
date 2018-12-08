#include "integer.h"
#include "bytecode.h"

STATE op_ipush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER value = bytecode_read_int(program);

    stack_push(stack, object_of_int(value));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_iadd(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a + b));

    return state;
}

STATE op_isub(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a - b));

    return state;
}

STATE op_idiv(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a / b)); // TODO figure out how to handle exceptions (in this case, division by zero)

    return state;
}

STATE op_imul(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a * b));

    return state;
}

STATE op_iand(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a & b));

    return state;
}

STATE op_ior(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a | b));

    return state;
}

STATE op_ixor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a ^ b));

    return state;
}

STATE op_inot(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(~a));

    return state;
}

STATE op_ilshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a << b));

    return state;
}

STATE op_irshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a >> b));

    return state;
}

STATE op_uipush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER val = bytecode_read_uint(program);

    stack_push(stack, object_of_uint(val));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_uiadd(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a + b));

    return state;
}

STATE op_uisub(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a - b));

    return state;
}

STATE op_uidiv(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a / b));

    return state;
}

STATE op_uimul(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a * b));

    return state;
}

STATE op_uiand(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a & b));

    return state;
}

STATE op_uior(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a | b));

    return state;
}

STATE op_uixor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a ^ b));

    return state;
}

STATE op_uinot(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(~a));

    return state;
}

STATE op_uilshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a << b));

    return state;
}

STATE op_uirshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a >> b));

    return state;
}
