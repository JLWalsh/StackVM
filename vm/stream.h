#ifndef STREAM_H
#define STREAM_H

#include <stdint.h>

typedef struct {
  char* raw;
  char* select_start;
} STREAM;

STREAM stream_create(char *raw);

char *stream_peek(STREAM *stream);

char *stream_find(STREAM *stream, char to_find);

void stream_select_start(STREAM *stream);

char* stream_select_end(STREAM *stream);

char *stream_advance(STREAM *stream, size_t advancement);

#endif /* STREAM_H */
