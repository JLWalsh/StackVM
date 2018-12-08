#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "type.h"

typedef enum EX_CATEGORY_T {
    EX_CATEGORY_VM
} EX_CATEGORY;

typedef UINTEGER EX_CODE;

typedef struct EXCEPTION_T {
    EX_CODE code;
} EXCEPTION;

EXCEPTION exception_create(EX_CODE code);

#endif /* EXCEPTION_H */
