#ifndef OBJECT_H
#define OBJECT_H

#include "type.h"

typedef union OBJECT_T {
    INTEGER  int_val;
    UINTEGER uint_val;
    LONG     long_val;
    ULONG    ulong_val;
    POINTER  ptr_val;
    float    float_val;
} OBJECT;

OBJECT object_of_float(float float_val);

OBJECT object_of_int(INTEGER int_val);

OBJECT object_of_uint(UINTEGER uint_val);

OBJECT object_of_long(LONG long_val);

OBJECT object_of_ulong(ULONG ulong_val);

OBJECT object_of_ptr(POINTER ptr_val);

#endif /* OBJECT_H */
