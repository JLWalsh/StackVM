#include "heap.h"

HEAP* heap_create(size_t initial_size)
{
    if (initial_size < sizeof(CHUNK)) {
        return NULL;
    }

    CHUNK* start    = (CHUNK*)malloc(initial_size);
    start->previous = NULL;
    start->next     = NULL;
    start->size     = initial_size - sizeof(CHUNK);

    HEAP* heap  = (HEAP*)malloc(sizeof(HEAP));
    heap->size  = initial_size;
    heap->start = start;

    return heap;
}

void heap_free(HEAP* heap)
{
    free(heap->start);
    free(heap);
}