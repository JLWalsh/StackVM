#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include <stdint.h>

typedef struct EXECUTABLE_HEADER_T {
    uint32_t program_start;
} EXECUTABLE_HEADER;

typedef struct EXECUTABLE_T {
    char* constants;
    char* program;
} EXECUTABLE;

EXECUTABLE executable_of(char* bytes);

#endif /* EXECUTABLE_H */
