#include "math.h"

int16_t math_int16_endian_swap(int16_t i)
{
    int16_t b0 = (i & 0xff00) >> 8;
    int16_t b1 = (i & 0xff) << 8;

    return b0 | b1;
}

int64_t math_int64_endian_swap(int64_t l)
{
    int64_t b0 = (l & 0xff00000000000000) >> 56;
    int64_t b1 = (l & 0xff000000000000) >> 40;
    int64_t b2 = (l & 0xff0000000000) >> 24;
    int64_t b3 = (l & 0xff00000000) >> 8;
    int64_t b4 = (l & 0xff000000) << 8;
    int64_t b5 = (l & 0xff0000) << 24;
    int64_t b6 = (l & 0xff00) << 40;
    int64_t b7 = (l & 0xff) << 56;

    return b0 | b1 | b2 | b3 | b4 | b5 | b6 | b7;
}

int32_t math_int32_endian_swap(int32_t ptr)
{
    int32_t b0 = (ptr & 0xff000000) >> 24;
    int32_t b1 = (ptr & 0xff0000) >> 8;
    int32_t b2 = (ptr & 0xff00) << 8;
    int32_t b3 = (ptr & 0xff) << 24;

    return b0 | b1 | b2 | b3;
}
