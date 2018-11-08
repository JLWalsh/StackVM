#include "object.h"

OBJECT object_of_int(INTEGER int_val)
{
    OBJECT o = { int_val };

    return o;
}

OBJECT object_of_ptr(POINTER ptr_val)
{
    OBJECT o = { ptr_val };

    return o;
}