#include "executable.h"
#include "constant.h"
#include "stream.h"

EXECUTABLE executable_of(char* bytes)
{
    STREAM executable = stream_create(bytes);

    EXECUTABLE_HEADER header = *((EXECUTABLE_HEADER*)stream_advance(&executable, sizeof(EXECUTABLE_HEADER)));

    size_t constants_size = header.program_start - stream_position(&executable);
    char*  constants      = (char*)malloc(constants_size);

    while (stream_position(&executable) < header.program_start) {
        CONSTANT_HEADER constant_header = *((CONSTANT_HEADER*)stream_advance(&executable, sizeof(CONSTANT_HEADER)));
        stream_select_start(&executable);
        stream_advance(&executable, constant_header.size);
        char* constant = stream_select_end(&executable);
    }
}
