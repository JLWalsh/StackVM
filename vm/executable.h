#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "stream.h"
#include <stdint.h>

typedef struct EXECUTABLE_HEADER_T {
    uint32_t program_start;
} EXECUTABLE_HEADER;

typedef struct EXECUTABLE_T {
    char*  constants;
    STREAM program;
} EXECUTABLE;

EXECUTABLE executable_from(char* bytes);

#endif /* EXECUTABLE_H */
