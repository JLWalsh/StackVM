#include "integer.h"
#include "bytecode.h"

void op_ipush(VM* vm)
{
    INTEGER value = bytecode_read_int(vm);

    stack_push(&vm->stack, object_of_int(value));
}

void op_iadd(VM* vm)
{
    INTEGER a = stack_pop(&vm->stack).int_val;
    INTEGER b = stack_pop(&vm->stack).int_val;

    stack_push(&vm->stack, object_of_int(a + b));
}

void op_isub(VM* vm)
{
    INTEGER a = stack_pop(&vm->stack).int_val;
    INTEGER b = stack_pop(&vm->stack).int_val;

    stack_push(&vm->stack, object_of_int(a - b));
}

void op_idiv(VM* vm)
{
    INTEGER a = stack_pop(&vm->stack).int_val;
    INTEGER b = stack_pop(&vm->stack).int_val;

    stack_push(&vm->stack, object_of_int(a / b)); // TODO figure out how to handle exceptions (in this case, division by zero)
}

void op_imul(VM* vm)
{
    INTEGER a = stack_pop(&vm->stack).int_val;
    INTEGER b = stack_pop(&vm->stack).int_val;

    stack_push(&vm->stack, object_of_int(a * b));
}

void op_iand(VM* vm)
{
    INTEGER a = stack_pop(&vm->stack).int_val;
    INTEGER b = stack_pop(&vm->stack).int_val;

    stack_push(&vm->stack, object_of_int(a & b));
}

void op_ior(VM* vm)
{
    INTEGER a = stack_pop(&vm->stack).int_val;
    INTEGER b = stack_pop(&vm->stack).int_val;

    stack_push(&vm->stack, object_of_int(a | b));
}

void op_ixor(VM* vm)
{
    INTEGER a = stack_pop(&vm->stack).int_val;
    INTEGER b = stack_pop(&vm->stack).int_val;

    stack_push(&vm->stack, object_of_int(a ^ b));
}

void op_inot(VM* vm)
{
    INTEGER a = stack_pop(&vm->stack).int_val;

    stack_push(&vm->stack, object_of_int(~a));
}

void op_ilshift(VM* vm)
{
    INTEGER a = stack_pop(&vm->stack).int_val;
    INTEGER b = stack_pop(&vm->stack).int_val;

    stack_push(&vm->stack, object_of_int(a << b));
}

void op_irshift(VM* vm)
{
    INTEGER a = stack_pop(&vm->stack).int_val;
    INTEGER b = stack_pop(&vm->stack).int_val;

    stack_push(&vm->stack, object_of_int(a >> b));
}

void op_uipush(VM* vm)
{
    UINTEGER val = bytecode_read_uint(vm);

    stack_push(&vm->stack, object_of_uint(val));
}

void op_uiadd(VM* vm)
{
    UINTEGER a = stack_pop(&vm->stack).uint_val;
    UINTEGER b = stack_pop(&vm->stack).uint_val;

    stack_push(&vm->stack, object_of_uint(a + b));
}

void op_uisub(VM* vm)
{
    UINTEGER a = stack_pop(&vm->stack).uint_val;
    UINTEGER b = stack_pop(&vm->stack).uint_val;

    stack_push(&vm->stack, object_of_uint(a - b));
}

void op_uidiv(VM* vm)
{
    UINTEGER a = stack_pop(&vm->stack).uint_val;
    UINTEGER b = stack_pop(&vm->stack).uint_val;

    stack_push(&vm->stack, object_of_uint(a / b));
}

void op_uimul(VM* vm)
{
    UINTEGER a = stack_pop(&vm->stack).uint_val;
    UINTEGER b = stack_pop(&vm->stack).uint_val;

    stack_push(&vm->stack, object_of_uint(a * b));
}

void op_uiand(VM* vm)
{
    UINTEGER a = stack_pop(&vm->stack).uint_val;
    UINTEGER b = stack_pop(&vm->stack).uint_val;

    stack_push(&vm->stack, object_of_uint(a & b));
}

void op_uior(VM* vm)
{
    UINTEGER a = stack_pop(&vm->stack).uint_val;
    UINTEGER b = stack_pop(&vm->stack).uint_val;

    stack_push(&vm->stack, object_of_uint(a | b));
}

void op_uixor(VM* vm)
{
    UINTEGER a = stack_pop(&vm->stack).uint_val;
    UINTEGER b = stack_pop(&vm->stack).uint_val;

    stack_push(&vm->stack, object_of_uint(a ^ b));
}

void op_uinot(VM* vm)
{
    UINTEGER a = stack_pop(&vm->stack).uint_val;

    stack_push(&vm->stack, object_of_uint(~a));
}

void op_uilshift(VM* vm)
{
    UINTEGER a = stack_pop(&vm->stack).uint_val;
    UINTEGER b = stack_pop(&vm->stack).uint_val;

    stack_push(&vm->stack, object_of_uint(a << b));
}

void op_uirshift(VM* vm)
{
    UINTEGER a = stack_pop(&vm->stack).uint_val;
    UINTEGER b = stack_pop(&vm->stack).uint_val;

    stack_push(&vm->stack, object_of_uint(a >> b));
}
