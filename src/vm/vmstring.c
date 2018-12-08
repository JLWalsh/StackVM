#include "vmstring.h"
#include "libstring.h"
#include <stdio.h>

// String operations
STATE op_scat(VM* vm)
{
    POINTER dest_ptr = stack_pop(stack).ptr_val;
    POINTER b_ptr    = stack_pop(stack).ptr_val;
    POINTER a_ptr    = stack_pop(stack).ptr_val;

    VMSTRING_HEADER* a_str    = (VMSTRING_HEADER*)heap_at(heap, a_ptr);
    VMSTRING_HEADER* b_str    = (VMSTRING_HEADER*)heap_at(heap, b_ptr);
    VMSTRING_HEADER* dest_str = (VMSTRING_HEADER*)heap_at(heap, dest_ptr);

    vmstring_concat(a_str, b_str, dest_str);

    stack_push(stack, object_of_ptr(dest_ptr));

    return state;
}

STATE op_sprint(VM* vm)
{
    POINTER str_ptr = stack_pop(stack).ptr_val;

    VMSTRING_HEADER* str = (VMSTRING_HEADER*)heap_at(heap, str_ptr);

    char* data = vmstring_data_ptr(str);
    for (int i = 0; i < str->length; i++) {
        printf("%c", data[i]);
    }

    return state;
}