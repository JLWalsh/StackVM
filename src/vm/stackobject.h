#ifndef STACK_OBJECT_H
#define STACK_OBJECT_H

#include "type.h"

typedef union STACK_OBJECT_T {
    INTEGER  int_val;
    UINTEGER uint_val;
    LONG     long_val;
    ULONG    ulong_val;
    POINTER  ptr_val;
    float    float_val;
} STACK_OBJECT;

STACK_OBJECT stack_object_of_float(float float_val);

STACK_OBJECT stack_object_of_int(INTEGER int_val);

STACK_OBJECT stack_object_of_uint(UINTEGER uint_val);

STACK_OBJECT stack_object_of_long(LONG long_val);

STACK_OBJECT stack_object_of_ulong(ULONG ulong_val);

STACK_OBJECT stack_object_of_ptr(POINTER ptr_val);

#endif /* STACK_OBJECT_H */
