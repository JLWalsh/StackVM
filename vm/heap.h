#ifndef HEAP_H
#define HEAP_H

#include "constants.h"
#include <stdlib.h>

typedef enum CHUNK_FLAGS_T {
    CHUNK_FLAGS_NONE,
    CHUNK_FLAGS_READONLY,
    CHUNK_FLAGS_ALLOCATED
} CHUNK_FLAGS;

typedef struct CHUNK_T {
    struct CHUNK_T* previous;
    struct CHUNK_T* next;
    size_t          size;
    INTEGER         flags;
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

POINTER heap_ptr_of_chunk(HEAP heap, CHUNK* chunk);

void heap_dump(HEAP heap);

#endif /* HEAP_H */
