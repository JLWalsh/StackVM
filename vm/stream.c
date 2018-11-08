#include "stream.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

STREAM stream_create(char* raw)
{
    STREAM stream;
    stream.current      = raw;
    stream.select_start = NULL;

    return stream;
}

char* stream_position(STREAM* stream)
{
    return stream->current;
}

void stream_seek(STREAM* stream, char* pos)
{
    stream->current = pos;
}

char* stream_advance(STREAM* stream, size_t advancement)
{
    char* value = stream->current;

    stream->current += advancement;

    return value;
}

void stream_select_start(STREAM* stream)
{
    stream->select_start = stream->current;
}

char* stream_select_end(STREAM* stream)
{
    size_t length = stream->current - stream->select_start + 1;

    char* selection = (char*)malloc(length * sizeof(char));
    strncpy(selection, stream->select_start, length);

    stream->select_start = NULL;

    return selection;
}
