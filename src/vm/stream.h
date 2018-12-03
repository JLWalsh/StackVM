#ifndef STREAM_H
#define STREAM_H

#include "type.h"
#include <stdint.h>
#include <stdlib.h>

typedef struct STREAM_T {
    void*   raw;
    POINTER current;
    size_t  size;
} STREAM;

STREAM stream_create(void* raw, size_t size);

POINTER stream_position(STREAM* stream);

void* stream_at(STREAM* stream, POINTER position);

void stream_seek(STREAM* stream, POINTER position);

void* stream_advance(STREAM* stream, size_t advancement);

void stream_free(STREAM stream);

#endif /* STREAM_H */
