#ifndef MATH_H
#define MATH_H

#include "type.h"

INTEGER math_int_to_big_endian(INTEGER i);
LONG    math_long_to_big_endian(LONG l);
POINTER math_ptr_to_big_endian(POINTER ptr);

#endif /* MATH_H */
