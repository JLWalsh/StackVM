#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stream.h"
#include "vm.h"

int main(int argc, char const *argv[])
{
  char d[] = { 1, 0, 2, 0, 72, 101, 108, 108, 111, 44, 32, 119, 111, 114, 108, 100, 33, '\0', 2, 0, 3, 0 };

  STREAM program = stream_create(&d);

  VM vm = vm_create(&program);

  vm_run(&vm);

  return 0;
}
