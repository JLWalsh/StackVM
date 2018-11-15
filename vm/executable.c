#include "executable.h"
#include "opcode.h"
#include "stream.h"
#include <string.h>

EXECUTABLE executable_from(char* bytes)
{
    STREAM program = stream_create(bytes);

    EXECUTABLE_HEADER header = *((EXECUTABLE_HEADER*)stream_advance(&program, sizeof(EXECUTABLE_HEADER)));

    size_t constants_size        = header.program_start - stream_position(&program) - 1;
    void*  extracted_constants   = malloc(constants_size);
    void*  constants_from_source = stream_advance(&program, constants_size);
    memcpy(extracted_constants, constants_from_source, constants_size);

    size_t program_size        = header.program_end - header.program_start + 1;
    void*  extracted_program   = malloc(program_size);
    void*  program_from_source = stream_advance(&program, program_size);
    memcpy(extracted_program, program_from_source, program_size);

    EXECUTABLE executable;
    executable.heap    = stream_create(extracted_constants); // TODO implement configurable heap size
    executable.program = stream_create(extracted_program);

    return executable;
}
