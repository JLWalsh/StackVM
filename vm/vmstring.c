#include "vmstring.h"
#include <string.h>

void vmstring_concat(VMSTRING_HEADER* a, VMSTRING_HEADER* b, VMSTRING_HEADER* out)
{
    ULONG new_len = a->length + b->length; // TODO maybe check for overflow?

    out->length = new_len;

    void* a_string_offset = vmstring_data_ptr(out);
    void* b_string_offset = a_string_offset + a->length;

    memcpy(a_string_offset, vmstring_data_ptr(a), a->length);
    memcpy(b_string_offset, vmstring_data_ptr(b), b->length);
}

void* vmstring_data_ptr(VMSTRING_HEADER* str)
{
    char* data_ptr = (char*)str + sizeof(VMSTRING_HEADER);

    return (void*)data_ptr;
}