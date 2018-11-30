#include "executor.h"
#include "opcode.h"
#include "vmstring.h"
#include <stdio.h>
#include <string.h>

STATE op_loadarg(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER offset   = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));
    INTEGER position = state.frame_position + offset;
    OBJECT  o        = stack_at(stack, position);

    stack_push(stack, o);

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_call(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    POINTER  fun_addr = *((POINTER*)stream_advance(program, sizeof(POINTER)));
    UINTEGER num_args = *((UINTEGER*)stream_advance(program, sizeof(UINTEGER)));

    POINTER return_addr = stream_position(program);

    state.instruction_ptr = fun_addr;
    state.frame_position  = stack_size(stack) - num_args;

    stack_push(stack, object_of_int(num_args));
    stack_push(stack, object_of_ptr(return_addr));
    stack_push(stack, object_of_ptr(state.frame_position));

    return state;
}

STATE op_return(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    OBJECT return_val     = stack_pop(stack);
    state.frame_position  = stack_pop(stack).ptr_val;
    state.instruction_ptr = stack_pop(stack).ptr_val;

    INTEGER num_args = stack_pop(stack).int_val;

    for (int i = 0; i < num_args; i++) {
        stack_pop(stack);
    }

    stack_push(stack, return_val);

    return state;
}

STATE op_halt(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER exit_code = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));

    state.running   = false;
    state.exit_code = exit_code;

    return state;
}

STATE op_print(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    OBJECT o = stack_pop(stack);

    printf("%i\n", o.int_val);

    return state;
}

// Pointer operations
STATE op_ppush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    POINTER pointer = *((POINTER*)stream_advance(program, sizeof(POINTER)));

    stack_push(stack, object_of_ptr(pointer));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_alloc(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG   alloc_size = *((ULONG*)stream_advance(program, sizeof(ULONG)));
    POINTER ptr        = heap_alloc(heap, alloc_size);

    stack_push(stack, object_of_ptr(ptr));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_dealloc(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    POINTER ptr = stack_pop(stack).ptr_val;
    heap_dealloc(heap, ptr);

    return state;
}

// String operations
STATE op_scat(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    POINTER dest_ptr = stack_pop(stack).ptr_val;
    POINTER b_ptr    = stack_pop(stack).ptr_val;
    POINTER a_ptr    = stack_pop(stack).ptr_val;

    VMSTRING_HEADER* a_str    = (VMSTRING_HEADER*)heap_at(heap, a_ptr);
    VMSTRING_HEADER* b_str    = (VMSTRING_HEADER*)heap_at(heap, b_ptr);
    VMSTRING_HEADER* dest_str = (VMSTRING_HEADER*)heap_at(heap, dest_ptr);

    dest_str->length = a_str->length + b_str->length;

    memcpy(vmstring_data_ptr(dest_str), vmstring_data_ptr(a_str), a_str->length);
    memcpy(vmstring_data_ptr(dest_str) + a_str->length, vmstring_data_ptr(b_str), b_str->length);

    stack_push(stack, object_of_ptr(dest_ptr));

    return state;
}

STATE op_sprint(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    POINTER          str_ptr = stack_pop(stack).ptr_val;
    VMSTRING_HEADER* str     = (VMSTRING_HEADER*)heap_at(heap, str_ptr);

    char* data = vmstring_data_ptr(str);
    for (int i = 0; i < str->length; i++) {
        printf("%c", data[i]);
    }

    return state;
}

STATE op_ipush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER value = *((INTEGER*)stream_advance(program, sizeof(INTEGER)));

    stack_push(stack, object_of_int(value));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_iadd(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a + b));

    return state;
}
