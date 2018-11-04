#include "stream.h"
#include <malloc.h>
#include <string.h>

STREAM stream_create(char *raw)
{
  STREAM stream;
  stream.raw = raw;
  stream.select_start = NULL;

  return stream;
}

char *stream_peek(STREAM *stream)
{
  return stream->raw;
}

char *stream_advance(STREAM *stream, size_t advancement)
{
  char *value = stream->raw;

  stream->raw += advancement;

  return value;
}

char *stream_find(STREAM *stream, char to_find) {
  char* pos = stream->raw;

  while(*pos != to_find) {
    pos += sizeof(char);
  }

  return pos;
}

void stream_select_start(STREAM *stream) {
  stream->select_start = stream->raw;
}

char *stream_select_end(STREAM *stream) {
  size_t length = stream->raw - stream->select_start + 1;
  
  char* selection = (char*) malloc(length * sizeof(char));
  strncpy(selection, stream->select_start, length);
  
  stream->select_start = NULL;

  return selection;
}
