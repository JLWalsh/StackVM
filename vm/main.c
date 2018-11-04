#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stream.h"
#include "object.h"

int main(int argc, char const *argv[])
{
  char d[] = {2, 0, 72, 101, 108, 108, 111, 44, 32, 119, 111, 114, 108, 100, 33, '\0'};
  STREAM s = stream_create(&d);
  OBJECT o = object_parse(&s);

  printf("type is %u\n", o.type);
  for(int i = 0; i < strlen(o.val.str_val); i++) {
    printf("%c", o.val.str_val[i]);
  }

  return 0;
}
