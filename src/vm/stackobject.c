#include "stackobject.h"

STACK_OBJECT stack_object_of_float(float float_val)
{
    STACK_OBJECT o;
    o.float_val = float_val;

    return o;
}

STACK_OBJECT stack_object_of_int(INTEGER int_val)
{
    STACK_OBJECT o;
    o.int_val = int_val;

    return o;
}

STACK_OBJECT stack_object_of_uint(UINTEGER uint_val)
{
    STACK_OBJECT o;
    o.uint_val = uint_val;

    return o;
}

STACK_OBJECT stack_object_of_long(LONG long_val)
{
    STACK_OBJECT o;
    o.long_val = long_val;

    return o;
}

STACK_OBJECT stack_object_of_ulong(ULONG ulong_val)
{
    STACK_OBJECT o;
    o.ulong_val = ulong_val;

    return o;
}

STACK_OBJECT stack_object_of_ptr(POINTER ptr_val)
{
    STACK_OBJECT o;
    o.ptr_val = ptr_val;

    return o;
}