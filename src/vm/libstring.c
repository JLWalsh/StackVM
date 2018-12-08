#include "libstring.h"
#include "math.h"
#include <string.h>

void vmstring_concat(VMSTRING_HEADER* a, VMSTRING_HEADER* b, VMSTRING_HEADER* out)
{
    VMSTRING_HEADER a_header = vmstring_read_header(a);
    VMSTRING_HEADER b_header = vmstring_read_header(b);

    ULONG new_len = a_header.length + b_header.length; // TODO maybe check for overflow?

    out->length = new_len;

    void* a_string_offset = vmstring_data_ptr(out);
    void* b_string_offset = a_string_offset + a_header.length;

    memcpy(a_string_offset, vmstring_data_ptr(a), a_header.length);
    memcpy(b_string_offset, vmstring_data_ptr(b), b_header.length);
}

VMSTRING_HEADER vmstring_read_header(void* str_ptr)
{
    VMSTRING_HEADER header = *((VMSTRING_HEADER*)str_ptr);

#ifdef VM_IS_LITTLE_ENDIAN
    header.length = (INTEGER)math_int16_endian_swap(header.length);
#endif

    return header;
}

void* vmstring_data_ptr(VMSTRING_HEADER* str)
{
    char* data_ptr = (char*)str + sizeof(VMSTRING_HEADER);

    return (void*)data_ptr;
}