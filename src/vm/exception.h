#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "type.h"

typedef UINTEGER EX_CODE;

typedef struct EXCEPTION_T {
    EX_CODE code;
} EXCEPTION;

EXCEPTION exception_init(EX_CODE code);

#endif /* EXCEPTION_H */
