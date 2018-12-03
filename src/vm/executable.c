#include "executable.h"
#include "opcode.h"
#include "stream.h"
#include <string.h>

EXECUTABLE executable_from(char* bytes)
{
    EXECUTABLE_HEADER* header           = (EXECUTABLE_HEADER*)bytes;
    void*              constants        = malloc(header->constants_length);
    size_t             constants_offset = sizeof(EXECUTABLE_HEADER);
    memcpy(constants, bytes + constants_offset, header->constants_length);

    size_t program_size   = header->executable_length - header->constants_length - sizeof(EXECUTABLE_HEADER);
    void*  program        = malloc(program_size);
    size_t program_offset = constants_offset + header->constants_length;
    memcpy(program, bytes + program_offset, program_size);

    EXECUTABLE executable;
    executable.constants = constants_create(constants, header->constants_length);
    executable.program   = stream_create(program, program_size);

    return executable;
}

void executable_free(EXECUTABLE executable)
{
    stream_free(executable.program);
}