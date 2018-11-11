#include "executable.h"
#include "stream.h"

EXECUTABLE executable_from(char* bytes)
{
    STREAM program = stream_create(bytes);

    EXECUTABLE_HEADER header = *((EXECUTABLE_HEADER*)stream_advance(&program, sizeof(EXECUTABLE_HEADER)));

    size_t constants_size         = header.program_start - stream_position(&program);
    void*  constants              = malloc(constants_size);
    void*  constants_from_program = stream_advance(&program, constants_size);
    memcpy(constants, constants_from_program, constants_size);

    EXECUTABLE executable;
    executable.constants = constants;
    executable.program   = program;

    return executable;
}
