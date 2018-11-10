#ifndef STREAM_H
#define STREAM_H

#include "type.h"
#include <stdint.h>
#include <stdlib.h>

typedef struct STREAM_T {
    char* current;
    char* start;
    char* select_start;
} STREAM;

STREAM stream_create(char* raw);

POINTER stream_position(STREAM* stream);

void stream_seek(STREAM* stream, POINTER position);

void stream_select_start(STREAM* stream);

void* stream_select_end(STREAM* stream);

void* stream_advance(STREAM* stream, size_t advancement);

#endif /* STREAM_H */
