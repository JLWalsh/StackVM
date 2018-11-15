#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "stream.h"
#include "type.h"

typedef struct EXECUTABLE_HEADER_T {
    ULONG program_start;
    ULONG program_end;
} EXECUTABLE_HEADER;

typedef struct EXECUTABLE_T {
    void*  constants;
    STREAM program;
} EXECUTABLE;

EXECUTABLE executable_from(char* bytes);

#endif /* EXECUTABLE_H */
