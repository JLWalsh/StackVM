#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "constants.h"
#include "stream.h"
#include "type.h"

typedef struct EXECUTABLE_HEADER_T {
    ULONG executable_length;
    ULONG constants_length;
} EXECUTABLE_HEADER;

typedef struct EXECUTABLE_T {
    CONSTANTS constants;
    STREAM    program;
} EXECUTABLE;

EXECUTABLE executable_from(char* bytes);

EXECUTABLE_HEADER executable_read_header(STREAM bytes_stream);

void executable_free(EXECUTABLE executable);

#endif /* EXECUTABLE_H */
