#ifndef TYPE_H
#define TYPE_H

#include <stdint.h>

#define VM_NULL 0

typedef int16_t  INTEGER;
typedef uint16_t UINTEGER;
typedef uint32_t POINTER;
typedef int64_t  LONG;
typedef uint64_t ULONG;
typedef int8_t   BYTE;
typedef UINTEGER OPCODE;

typedef union SERIALIZED_FLOAT_T {
    uint32_t raw;
    float    value;
} SERIALIZED_FLOAT;

#endif /* TYPE_H */
