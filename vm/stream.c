#include "stream.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

STREAM stream_create(char* raw)
{
    STREAM stream;
    stream.current      = raw;
    stream.start        = raw;
    stream.select_start = NULL;

    return stream;
}

POINTER stream_position(STREAM* stream)
{
    return (POINTER)(stream->current - stream->start);
}

void stream_seek(STREAM* stream, POINTER position)
{
    stream->current = stream->start + position;
}

void* stream_advance(STREAM* stream, size_t advancement)
{
    char* value = stream->current;

    stream->current += advancement;

    return value;
}

void stream_select_start(STREAM* stream)
{
    stream->select_start = stream->current;
}

void* stream_select_end(STREAM* stream)
{
    size_t length = stream->current - stream->select_start + 1;

    void* selection = malloc(length * sizeof(char));
    strncpy(selection, stream->select_start, length);

    stream->select_start = NULL;

    return selection;
}
