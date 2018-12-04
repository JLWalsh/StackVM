#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vm/executable.h>
#include <vm/heap.h>
#include <vm/opcode.h>
#include <vm/vm.h>


int main(int argc, char const* argv[])
{
    // char exe[] = {
    //     39, 0, 0, 0, // PROGRAM START POS
    //     49, 0, 0, 0,
    //     // CONSTANTS
    //     6, 0, // LEN
    //     72, 101, 108, 108, 111, 32, // STR VAL
    //     6, 0, // LEN
    //     119, 111, 114, 108, 100, 33, // STR VAL
    //     0, 0, // NEW LEN
    //     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // FUTURE STR VAL
    //     // PROGRAM START
    //     OP_I_PUSH, 0, 0,
    //     OP_I_PUSH, 8, 0,
    //     OP_S_CAT, 16, 0,
    //     OP_S_PRINT, 16, 0,
    //     OP_HALT
    // };

    char exe[] = {
        63, 0, 0, 0, 0, 0, 0, 0, // EXE LEN
        16, 0, 0, 0, 0, 0, 0, 0, // CONSTS LEN
        // CONSTANTS
        6, 0, // LEN
        72, 101, 108, 108, 111, 32, // STR VAL (Hello )
        6, 0, // LEN
        119, 111, 114, 108, 100, 33, // STR VAL (world!)
        // PROGRAM START
        OP_P_PUSH, 0,
        0, 0, 0, 0, // Push ptr 0
        OP_P_PUSH, 0,
        8, 0, 0, 0, // Push ptr 8
        OP_ALLOC, 0,
        32, 0, 0, 0, 0, 0, 0, 0, // 32 bytes: size of Hello world!
        // Now our storage pointer is on the stack, we are ready to call string cat
        OP_S_CAT, 0, // String cat returns the storage pointer onto the stack
        OP_S_PRINT, 0,
        OP_HALT, 0,
        OP_S_PRINT, 0,
        // Str @ ptr
        OP_HALT, 0
    };

    EXECUTABLE executable = executable_from(&exe);

    VM vm = vm_create(executable);

    int16_t exit_code = vm_run(&vm);

    executable_free(executable);
    vm_free(vm);

    return exit_code;
    // return 0;
}
