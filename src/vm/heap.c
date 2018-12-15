#include "heap.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

HEAP heap_create(ULONG start_size)
{
    size_t chunk_headers_size = sizeof(CHUNK);
    size_t full_size          = chunk_headers_size + start_size;

    char*  heap_start  = (char*)malloc(full_size + 1);
    CHUNK* first_chunk = (CHUNK*)(heap_start + 1); // First byte is reserved for VM_NULL

    first_chunk->previous = NULL;
    first_chunk->next     = NULL;
    first_chunk->size     = start_size;

    heap_chunk_reset_flags(first_chunk);

    HEAP heap;
    heap.size  = start_size;
    heap.start = (char*)first_chunk;

    return heap;
}

void heap_free(HEAP heap)
{
    free(heap.start - 1); // First byte is reserved for VM_NULL
}

POINTER heap_alloc(HEAP* heap, ULONG size)
{
    CHUNK* current = (CHUNK*)heap->start;

    while (current != NULL) {
        bool is_allocated = heap_chunk_read_flag(current, CHUNK_FLAGS_ALLOCATED);
        bool is_readonly  = heap_chunk_read_flag(current, CHUNK_FLAGS_READONLY);
        if (current->size >= size && !is_allocated && !is_readonly) {
            POINTER pointer = heap_ptr_of_chunk(heap, current);
            heap_chunk_enable_flag(current, CHUNK_FLAGS_ALLOCATED);

            if (current->size > size + sizeof(CHUNK)) {
                CHUNK* data_end = (CHUNK*)((char*)current + sizeof(CHUNK) + size);

                if (current->next != NULL) {
                    current->next->previous = data_end;
                }

                data_end->next     = current->next;
                data_end->previous = current;
                current->next      = data_end;

                heap_chunk_reset_flags(data_end);
                data_end->size = current->size - sizeof(CHUNK) - size;
                current->size  = size;
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
    CHUNK* chunk = heap_chunk_of_ptr(heap, value);

    heap_chunk_disable_flag(chunk, CHUNK_FLAGS_ALLOCATED);
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

CHUNK* heap_chunk_of_ptr(HEAP* heap, POINTER ptr)
{
    char* chunk_ptr = heap->start + ptr;

    return (CHUNK*)chunk_ptr;
}

void heap_chunk_enable_flag(CHUNK* chunk, CHUNK_FLAGS flags)
{
    chunk->flags |= (flags);
}

void heap_chunk_disable_flag(CHUNK* chunk, CHUNK_FLAGS flags)
{
    chunk->flags &= ~flags;
}

void heap_chunk_reset_flags(CHUNK* chunk)
{
    chunk->flags = 0;
}

bool heap_chunk_read_flag(CHUNK* chunk, CHUNK_FLAGS flag)
{
    return chunk->flags & flag;
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