#include "object.h"

OBJECT object_of_int(int16_t int_val)
{
  OBJECT object;
  object.type = INT;
  object.val.int_val = int_val;

  return object;
}

OBJECT object_of_uint(uint16_t uint_val)
{
  OBJECT object;
  object.type = UINT;
  object.val.uint_val = uint_val;

  return object;
}

OBJECT object_of_str(char *str_val)
{
  OBJECT object;
  object.type = STR;
  object.val.str_val = str_val;

  return object;
}

OBJECT object_parse(STREAM *stream) {
  uint16_t type = *((uint16_t *) stream_advance(stream, sizeof(uint16_t)));

  switch(type) {
    case INT: {
      int16_t int_val = *((int16_t *) stream_advance(stream, sizeof(int16_t)));

      return object_of_int(int_val);
    }
    case UINT: {
      uint16_t uint_val = *((uint16_t *) stream_advance(stream, sizeof(uint16_t)));

      return object_of_uint(uint_val);
    }
    case STR: {
      stream_select_start(stream);

      while(*stream_peek(stream) != '\0') {
        stream_advance(stream, sizeof(char));
      }

      char* str_val = stream_select_end(stream);
      
      return object_of_str(str_val);
    }
  }
}