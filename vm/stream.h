#ifndef STREAM_H
#define STREAM_H

#include <stdint.h>
#include <stdlib.h>

typedef struct STREAM_T {
    char* current;
    char* select_start;
} STREAM;

STREAM stream_create(char* raw);

char* stream_peek(STREAM* stream);

void stream_seek(STREAM* stream, char*);

void stream_select_start(STREAM* stream);

char* stream_select_end(STREAM* stream);

char* stream_advance(STREAM* stream, size_t advancement);

#endif /* STREAM_H */
