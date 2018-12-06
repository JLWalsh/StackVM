#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vm/bytecode.h>
#include <vm/executable.h>
#include <vm/heap.h>
#include <vm/opcode.h>
#include <vm/vm.h>

int main(int argc, char const* argv[])
{
    // char exe[] = {
    //     0, 0, 0, 0, 0, 0, 0, 63, // EXE LEN
    //     0, 0, 0, 0, 0, 0, 0, 16, // CONSTS LEN
    //     // CONSTANTS
    //     0, 6, // LEN
    //     72, 101, 108, 108, 111, 32, // STR VAL (Hello )
    //     0, 6, // LEN
    //     119, 111, 114, 108, 100, 33, // STR VAL (world!)
    //     // PROGRAM START
    //     0, OP_P_PUSH,
    //     0, 0, 0, 0, // Push ptr 0
    //     0, OP_P_PUSH,
    //     0, 0, 0, 8, // Push ptr 8
    //     0, OP_ALLOC,
    //     0, 0, 0, 0, 0, 0, 0, 32, // 32 bytes: size of Hello world!
    //     // Now our storage pointer is on the stack, we are ready to call string cat
    //     0, OP_S_CAT, // String cat returns the storage pointer onto the stack
    //     0, OP_S_PRINT,
    //     0, OP_HALT, 0, 0
    // };
    uint32_t a   = 0xc3a31dbc;
    STREAM   t   = stream_create(&a, 4);
    float    val = bytecode_read_float(&t);
    printf("Value is %f", val);

    char exe[] = {
        0, 0, 0, 0, 0, 0, 0, 75, // EXE LEN
        0, 0, 0, 0, 0, 0, 0, 16, // CONSTS LEN
        // CONSTANTS
        0, 6, // LEN
        72, 101, 108, 108, 111, 32, // STR VAL (Hello )
        0, 6, // LEN
        119, 111, 114, 108, 100, 33, // STR VAL (world!)
        // PROGRAM START
        0, OP_P_PUSH,
        0, 0, 0, 0, // Push ptr 0
        0, OP_P_PUSH,
        0, 0, 0, 8, // Push ptr 8
        0, OP_ALLOC,
        0, 0, 0, 0, 0, 0, 0, 32, // 32 bytes: size of Hello world!
        // Now our storage pointer is on the stack, we are ready to call string cat
        0, OP_S_CAT, // String cat returns the storage pointer onto the stack
        0, OP_S_PRINT,
        0, OP_I_PUSH, 0, 10,
        0, OP_I_PUSH, 0, 25,
        0, OP_I_AND,
        0, OP_PRINT,
        0, OP_HALT, 0, 0
    };

    EXECUTABLE executable = executable_from(&exe);
    VM         vm         = vm_create(executable);

    int16_t exit_code = vm_run(&vm);

    executable_free(executable);
    vm_free(vm);

    return exit_code;
    // return 0;
}
