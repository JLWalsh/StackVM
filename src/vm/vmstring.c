#include "vmstring.h"
#include "libstring.h"
#include <stdio.h>

// String operations
void op_scat(VM* vm)
{
    POINTER dest_ptr = stack_pop(&vm->stack).ptr_val;
    POINTER b_ptr    = stack_pop(&vm->stack).ptr_val;
    POINTER a_ptr    = stack_pop(&vm->stack).ptr_val;

    VMSTRING_HEADER* a_str    = (VMSTRING_HEADER*)heap_at(&vm->heap, a_ptr);
    VMSTRING_HEADER* b_str    = (VMSTRING_HEADER*)heap_at(&vm->heap, b_ptr);
    VMSTRING_HEADER* dest_str = (VMSTRING_HEADER*)heap_at(&vm->heap, dest_ptr);

    vmstring_concat(a_str, b_str, dest_str);

    stack_push(&vm->stack, object_of_ptr(dest_ptr));
}

void op_sprint(VM* vm)
{
    POINTER str_ptr = stack_pop(&vm->stack).ptr_val;

    VMSTRING_HEADER* str = (VMSTRING_HEADER*)heap_at(&vm->heap, str_ptr);

    char* data = vmstring_data_ptr(str);
    for (int i = 0; i < str->length; i++) {
        printf("%c", data[i]);
    }
}