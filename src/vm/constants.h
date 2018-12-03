#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "type.h"

typedef struct CONSTANTS_T {
    void* data;
    ULONG length;
} CONSTANTS;

CONSTANTS constants_create(void* data, ULONG length);

void constants_free(CONSTANTS constants);

#endif /* CONSTANTS_H */
