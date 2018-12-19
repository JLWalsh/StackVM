#ifndef OBJECT_H
#define OBJECT_H

#include "type.h"

typedef struct OBJECT_FUNC_TABLE_T {
    POINTER* func_ptrs;
    UINTEGER table_size;
} OBJECT_FUNC_TABLE;

typedef struct OBJECT_T {
    OBJECT_FUNC_TABLE func_table;
    OBJECT_FUNC_TABLE vfunc_table[];
    UINTEGER          object_id;
    ULONG             bytecode_size;
    void*             bytecode;
} OBJECT;

#endif /* OBJECT_H */
