#ifndef TYPE_H
#define TYPE_H

#include <stdint.h>

enum TYPE {
    T_INT,
    T_STR,
    T_PTR,
    T_DBL,
    T_FLT,
};

typedef uint16_t OBJECT_TYPE;
typedef int16_t  INTEGER;
typedef float    FLOAT;
typedef double   DOUBLE;

#endif /* TYPE_H */
