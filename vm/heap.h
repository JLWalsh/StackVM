#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

typedef struct CHUNK_T {
    struct CHUNK* previous;
    struct CHUNK* next;
    size_t        size;
} CHUNK;

typedef struct HEAP_T {
    CHUNK* start;
    size_t size;
} HEAP;

HEAP* heap_create(size_t initial_size);
void  heap_free(HEAP* heap);

#endif /* HEAP_H */
