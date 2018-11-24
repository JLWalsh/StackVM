#ifndef OBJECT_H
#define OBJECT_H

#include "type.h"

typedef union OBJECT_T {
    INTEGER int_val;
    POINTER ptr_val;
} OBJECT;

OBJECT object_of_int(INTEGER int_val);

OBJECT object_of_ptr(POINTER ptr_val);

#endif /* OBJECT_H */
