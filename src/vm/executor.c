#include "executor.h"
#include "bytecode.h"
#include "opcode.h"
#include "vmstring.h"
#include <stdio.h>
#include <string.h>

void op_loadarg(VM* vm)
{
    INTEGER offset   = bytecode_read_int(&vm->program);
    INTEGER position = vm->state.frame_position + offset;
    OBJECT  o        = stack_at(&vm->stack, position);

    stack_push(&vm->stack, o);

    vm->state.instruction_ptr = stream_position(&vm->program);
}

void op_call(VM* vm)
{
    POINTER  fun_addr = bytecode_read_ptr(&vm->program);
    UINTEGER num_args = bytecode_read_uint(&vm->program);

    POINTER return_addr = stream_position(&vm->program);

    vm->state.instruction_ptr = fun_addr;
    vm->state.frame_position  = stack_size(&vm->stack) - num_args;

    stack_push(&vm->stack, object_of_int(num_args));
    stack_push(&vm->stack, object_of_ptr(return_addr));
    stack_push(&vm->stack, object_of_int(vm->state.frame_position));
}

void op_return(VM* vm)
{
    OBJECT return_val         = stack_pop(&vm->stack);
    vm->state.frame_position  = stack_pop(&vm->stack).ptr_val;
    vm->state.instruction_ptr = stack_pop(&vm->stack).ptr_val;

    INTEGER num_args = stack_pop(&vm->stack).int_val;

    for (int i = 0; i < num_args; i++) {
        stack_pop(&vm->stack);
    }

    stack_push(&vm->stack, return_val);
}

void op_halt(VM* vm)
{
    // Use vm_exit here
    INTEGER exit_code = bytecode_read_int(&vm->program);

    vm->state.running   = false;
    vm->state.exit_code = exit_code;
}

void op_print(VM* vm)
{
    OBJECT o = stack_pop(&vm->stack);

    printf("%i\n", o.int_val);
}

// Pointer operations
void op_ppush(VM* vm)
{
    POINTER pointer = bytecode_read_ptr(&vm->program);

    stack_push(&vm->stack, object_of_ptr(pointer));

    vm->state.instruction_ptr = stream_position(&vm->program);
}

void op_alloc(VM* vm)
{
    ULONG   alloc_size = bytecode_read_ulong(&vm->program);
    POINTER ptr        = heap_alloc(&vm->heap, alloc_size);

    stack_push(&vm->stack, object_of_ptr(ptr));

    vm->state.instruction_ptr = stream_position(&vm->program);
}

void op_dealloc(VM* vm)
{
    POINTER ptr = stack_pop(&vm->stack).ptr_val;
    heap_dealloc(&vm->heap, ptr);
}