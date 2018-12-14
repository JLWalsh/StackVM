#ifndef HEAP_H
#define HEAP_H

#include "type.h"
#include <stdbool.h>
#include <stdlib.h>

typedef enum CHUNK_FLAGS_T {
    CHUNK_FLAGS_READONLY  = 1 << 0,
    CHUNK_FLAGS_ALLOCATED = 1 << 1
} CHUNK_FLAGS;

typedef struct CHUNK_T {
    struct CHUNK_T* previous;
    struct CHUNK_T* next;
    ULONG           size;
    INTEGER         flags;
} CHUNK;

typedef struct HEAP_T {
    char* start;
    ULONG size;
} HEAP;

HEAP heap_create(ULONG start_size);

void heap_free(HEAP heap);

POINTER heap_alloc(HEAP* heap, ULONG size);

void heap_dealloc(HEAP* heap, POINTER value);

void* heap_at(HEAP* heap, POINTER value);

POINTER heap_ptr_of_chunk(HEAP* heap, CHUNK* chunk);

CHUNK* heap_chunk_of_ptr(HEAP* heap, POINTER ptr);

void heap_chunk_enable_flag(CHUNK* chunk, CHUNK_FLAGS flags);

void heap_chunk_disable_flag(CHUNK* chunk, CHUNK_FLAGS flags);

void heap_chunk_reset_flags(CHUNK* chunk);

bool heap_chunk_read_flag(CHUNK* chunk, CHUNK_FLAGS flag);

void heap_dump(HEAP* heap);

#endif /* HEAP_H */
