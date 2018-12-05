#include "math.h"

INTEGER math_int_to_big_endian(INTEGER i)
{
    INTEGER b0 = (i & 0xff00) >> 8;
    INTEGER b1 = (i & 0xff) << 8;

    return b0 | b1;
}

LONG math_long_to_big_endian(LONG l)
{
    LONG b0 = (l & 0xff00000000000000) >> 56;
    LONG b1 = (l & 0xff000000000000) >> 40;
    LONG b2 = (l & 0xff0000000000) >> 24;
    LONG b3 = (l & 0xff00000000) >> 8;
    LONG b4 = (l & 0xff000000) << 8;
    LONG b5 = (l & 0xff0000) << 24;
    LONG b6 = (l & 0xff00) << 40;
    LONG b7 = (l & 0xff) << 56;

    return b0 | b1 | b2 | b3 | b4 | b5 | b6 | b7;
}

POINTER math_ptr_to_big_endian(POINTER ptr)
{
    POINTER b0 = (ptr & 0xff000000) >> 24;
    POINTER b1 = (ptr & 0xff0000) >> 8;
    POINTER b2 = (ptr & 0xff00) << 8;
    POINTER b3 = (ptr & 0xff) << 24;

    return b0 | b1 | b2 | b3;
}
