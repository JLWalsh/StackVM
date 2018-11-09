#include "opcode.h"
#include "stream.h"
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const* argv[])
{
    char d[] = {
        OP_PUSH, 5, 0, // PUSH
        OP_CALL, 10, 0, 1, 0,
        OP_PRINT,
        OP_HALT,
        OP_LOADARG, 0, 0,
        OP_PUSH, 2, 0,
        OP_ADD,
        OP_RETURN
    };

    STREAM program = stream_create(&d);

    VM vm = vm_create(&program);

    vm_run(&vm);

    return 0;
}
