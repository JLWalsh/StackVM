#ifndef VMSTRING_H
#define VMSTRING_H

#include "type.h"

typedef struct VMSTRING_HEADER_T {
    INTEGER length; // TODO change this back to ULONG
} VMSTRING_HEADER;

void vmstring_concat(VMSTRING_HEADER* a, VMSTRING_HEADER* b, VMSTRING_HEADER* out);

#endif /* VMSTRING_H */
