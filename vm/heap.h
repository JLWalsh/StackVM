#ifndef HEAP_H
#define HEAP_H

#include "constants.h"
#include <stdlib.h>

typedef enum CHUNK_FLAGS_T {
    CHUNK_NONE,
    CHUNK_READONLY = 0xf,
} CHUNK_FLAGS;

typedef struct CHUNK_T {
    struct CHUNK_T* previous;
    struct CHUNK_T* next;
    size_t          size;
    CHUNK_FLAGS     flags;
} CHUNK;

typedef struct HEAP_T {
    char*  start;
    size_t size;
} HEAP;

HEAP heap_from(CONSTANTS constants, size_t min_writable_size);

void heap_free(HEAP heap);

POINTER heap_alloc(HEAP heap, size_t size);

void heap_dealloc(HEAP heap, POINTER value);

void* heap_at(HEAP heap, POINTER value);

void heap_dump(HEAP heap);

#endif /* HEAP_H */
