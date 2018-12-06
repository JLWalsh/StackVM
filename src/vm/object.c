#include "object.h"

OBJECT object_of_int(INTEGER int_val)
{
    OBJECT o;
    o.int_val = int_val;

    return o;
}

OBJECT object_of_uint(UINTEGER uint_val)
{
    OBJECT o;
    o.uint_val = uint_val;

    return o;
}

OBJECT object_of_long(LONG long_val)
{
    OBJECT o;
    o.long_val = long_val;

    return o;
}

OBJECT object_of_ptr(POINTER ptr_val)
{
    OBJECT o;
    o.ptr_val = ptr_val;

    return o;
}