#include "stream.h"
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const* argv[])
{
    char d[] = {
        1, 0,
        2, 0, 68, 111, 111, 116, 33, '\0',
        1, 0,
        2, 0, 72, 101, 108, 108, 111, 44, 32, 119, 111, 114, 108, 100, 33, '\0',
        4, 0,
        2, 0,
        3, 0
    };

    STREAM program = stream_create(&d);

    VM vm = vm_create(&program);

    vm_run(&vm);

    return 0;
}
