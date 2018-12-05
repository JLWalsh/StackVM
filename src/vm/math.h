#ifndef MATH_H
#define MATH_H

#include <stdint.h>

int16_t math_int16_to_big_endian(int16_t i);
int64_t math_int64_to_big_endian(int64_t l);
int32_t math_int32_to_big_endian(int32_t ptr);

#endif /* MATH_H */
