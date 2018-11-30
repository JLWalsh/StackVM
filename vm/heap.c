#include "heap.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

HEAP heap_from(CONSTANTS constants, ULONG min_writable_size)
{
    size_t chunk_headers_size = sizeof(CHUNK) * 2;
    size_t size               = chunk_headers_size + constants.length + min_writable_size;

    CHUNK* constants_chunk = (CHUNK*)((char*)malloc(size + 1) + 1); // First byte is reserved for VM_NULL

    constants_chunk->previous = NULL;
    constants_chunk->next     = NULL;
    constants_chunk->size     = constants.length;
    constants_chunk->flags    = CHUNK_FLAGS_NONE;
    constants_chunk->flags |= 1 << CHUNK_FLAGS_READONLY;
    constants_chunk->flags |= 1 << CHUNK_FLAGS_ALLOCATED;

    char* data = (char*)constants_chunk + sizeof(CHUNK);
    memcpy(data, constants.data, constants.length);

    CHUNK* writable_chunk    = (CHUNK*)((char*)constants_chunk + sizeof(CHUNK) + constants.length);
    writable_chunk->next     = NULL;
    writable_chunk->previous = constants_chunk;
    writable_chunk->size     = min_writable_size;
    writable_chunk->flags    = CHUNK_FLAGS_NONE;

    constants_chunk->next = writable_chunk;

    HEAP heap;
    heap.size  = size;
    heap.start = (char*)constants_chunk;

    return heap;
}

void heap_free(HEAP heap)
{
    free(heap.start);
}

POINTER heap_alloc(HEAP* heap, ULONG size)
{
    CHUNK* current = (CHUNK*)heap->start;

    while (current != NULL) {
        INTEGER flags        = current->flags;
        bool    is_allocated = (flags >> CHUNK_FLAGS_ALLOCATED) & 1;
        bool    is_readonly  = (flags >> CHUNK_FLAGS_READONLY) & 1;

        if (current->size >= size && !is_allocated && !is_readonly) {
            POINTER pointer = heap_ptr_of_chunk(heap, current);

            current->flags |= 1 << CHUNK_FLAGS_ALLOCATED;

            if (current->size > size + sizeof(CHUNK)) {
                CHUNK* data_end = (CHUNK*)((char*)current + sizeof(CHUNK) + size);

                if (current->next != NULL) {
                    current->next->previous = data_end;
                }

                data_end->next     = current->next;
                data_end->previous = current;
                current->next      = data_end;

                data_end->flags = CHUNK_FLAGS_NONE;
                data_end->size  = current->size - sizeof(CHUNK) - size;
                current->size   = size;
            }

            return pointer;
        }

        current = current->next;
    }

    if (current == NULL) {
        return VM_NULL;
    }

    return VM_NULL;
}

void heap_dealloc(HEAP* heap, POINTER value)
{
    char*  data_start  = &heap->start[value];
    CHUNK* chunk_start = (CHUNK*)(data_start - sizeof(CHUNK));

    chunk_start->flags &= ~(1 << CHUNK_FLAGS_ALLOCATED); // TODO make method that stitches free chunks back together (basically the start of the GC)
}

void* heap_at(HEAP* heap, POINTER value)
{
    char* chunk_start = &heap->start[value];
    chunk_start += sizeof(CHUNK);

    return (void*)chunk_start;
}

POINTER heap_ptr_of_chunk(HEAP* heap, CHUNK* chunk)
{
    POINTER offset_from_start = (char*)chunk - heap->start;

    return offset_from_start;
}

void heap_dump(HEAP* heap)
{
    int chunk_counter = 0;

    CHUNK* current = (CHUNK*)heap->start;
    for (;;) {
        if (current == NULL) {
            break;
        }

        printf("Chunk #%i (Flag: %i, size: %i):\n", chunk_counter, current->flags, current->size);

        char* data = (char*)current + sizeof(CHUNK);
        for (int i = 0; i < current->size; i++) {
            printf("%i\n", data[i]);
        }
        chunk_counter++;
        current = current->next;
    }
}