#include "executable.h"
#include "math.h"
#include "opcode.h"
#include "stream.h"
#include <string.h>

EXECUTABLE executable_from(char* bytes)
{
    STREAM bytes_stream = stream_create(bytes);

    EXECUTABLE_HEADER header = executable_read_header(&bytes_stream);

    void* constants = NULL;
    if (header.constants_length > 0) {
        constants = malloc(header.constants_length);
        memcpy(constants, stream_advance(&bytes_stream, header.constants_length), header.constants_length);
    }

    size_t program_size = header.executable_length - header.constants_length - sizeof(EXECUTABLE_HEADER);
    void*  program      = malloc(program_size);
    memcpy(program, stream_advance(&bytes_stream, program_size), program_size);

    EXECUTABLE executable;
    executable.constants        = constants;
    executable.constants_length = header.constants_length;
    executable.program          = stream_create(program);

    return executable;
}

EXECUTABLE_HEADER executable_read_header(STREAM* bytes_stream)
{
    EXECUTABLE_HEADER header;
    header.executable_length = *((ULONG*)stream_advance(bytes_stream, sizeof(ULONG)));
    header.constants_length  = *((ULONG*)stream_advance(bytes_stream, sizeof(ULONG)));

#ifdef VM_IS_LITTLE_ENDIAN
    header.constants_length  = (ULONG)math_int64_endian_swap(header.constants_length);
    header.executable_length = (ULONG)math_int64_endian_swap(header.executable_length);
#endif

    return header;
}

void executable_free(EXECUTABLE executable)
{
    stream_free(executable.program);
}