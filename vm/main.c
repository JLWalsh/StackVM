#include "opcode.h"
#include "stream.h"
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const* argv[])
{
    char d[] = {
        OP_PUSH, 22, 0, // PUSH
        OP_PRINT,
        OP_HALT
    };

    STREAM program = stream_create(&d);

    VM vm = vm_create(&program);

    vm_run(&vm);

    return 0;
}
