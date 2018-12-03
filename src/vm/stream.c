#include "stream.h"

STREAM stream_create(void* raw, size_t size)
{
    STREAM stream;
    stream.raw     = raw;
    stream.current = 0;
    stream.size    = size;

    return stream;
}

POINTER stream_position(STREAM* stream)
{
    return stream->current;
}

void* stream_at(STREAM* stream, POINTER position)
{
    char* raw_chars = (char*)stream->raw;

    return (void*)(raw_chars + position);
}

void stream_seek(STREAM* stream, POINTER position)
{
    stream->current = position;
}

void* stream_advance(STREAM* stream, size_t advancement)
{
    void* value = stream_at(stream, stream->current);

    stream->current += advancement;

    return value;
}

void stream_free(STREAM stream)
{
    free(stream.raw);
}