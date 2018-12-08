#ifndef MATH_H
#define MATH_H

#include <stdint.h>

int16_t math_int16_endian_swap(int16_t i);
int64_t math_int64_endian_swap(int64_t l);
int32_t math_int32_endian_swap(int32_t ptr);

#endif /* MATH_H */
