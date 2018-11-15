#include "vmstring.h"
#include <string.h>

void vmstring_concat(VMSTRING_HEADER* a, VMSTRING_HEADER* b, VMSTRING_HEADER* out)
{
    ULONG new_len = a->length + b->length; // TODO maybe check for overflow?

    out->length = new_len;

    void* a_string_offset = out + sizeof(VMSTRING_HEADER);
    void* b_string_offset = a_string_offset + a->length;

    memcpy(a_string_offset, a + sizeof(VMSTRING_HEADER), a->length);
    memcpy(b_string_offset, b + sizeof(VMSTRING_HEADER), b->length);
}