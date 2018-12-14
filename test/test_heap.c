#include <stdbool.h>
#include <unity.h>
#include <vm/heap.h>

int number_of_chunks(HEAP heap)
{
    CHUNK* current    = (CHUNK*)heap.start;
    int    num_chunks = 0;

    while (current != NULL) {
        num_chunks++;
        current = current->next;
    }

    return num_chunks;
}

void test_heap_alloc_should_create_new_chunk_out_of_remaining_memory()
{
    HEAP heap = heap_create(120);

    heap_alloc(&heap, 60);
    TEST_ASSERT_EQUAL_INT(2, number_of_chunks(heap));

    heap_free(heap);
}

void test_heap_alloc_should_create_chunk_with_specified_size()
{
    HEAP heap = heap_create(120);

    POINTER ptr = heap_alloc(&heap, 60);

    CHUNK* allocated_chunk = heap_chunk_of_ptr(&heap, ptr);
    TEST_ASSERT_EQUAL_UINT(60, allocated_chunk->size);
    TEST_ASSERT_TRUE(heap_chunk_read_flag(allocated_chunk, CHUNK_FLAGS_ALLOCATED));

    heap_free(heap);
}

void test_heap_alloc_should_not_split_chunks_when_not_enough_memory_for_new_chunk()
{
    int  first_chunk_size = 120;
    HEAP heap             = heap_create(first_chunk_size);

    POINTER ptr = heap_alloc(&heap, first_chunk_size);

    TEST_ASSERT_EQUAL_INT(1, number_of_chunks(heap));
    TEST_ASSERT_EQUAL_UINT(first_chunk_size, heap_chunk_of_ptr(&heap, ptr)->size);

    heap_free(heap);
}

void test_heap_alloc_should_return_null_if_allocation_exceeds_memory_available()
{
    int  memory_available = 120;
    HEAP heap             = heap_create(memory_available);

    POINTER ptr = heap_alloc(&heap, memory_available + 20);

    TEST_ASSERT_EQUAL_INT(VM_NULL, ptr);

    heap_free(heap);
}

void test_heap_dealloc_should_remove_allocated_flag()
{
    HEAP    heap            = heap_create(120);
    POINTER allocated_ptr   = heap_alloc(&heap, 5);
    CHUNK*  allocated_chunk = heap_chunk_of_ptr(&heap, allocated_ptr);

    heap_dealloc(&heap, allocated_ptr);
    bool is_allocated = heap_chunk_read_flag(allocated_chunk, CHUNK_FLAGS_ALLOCATED);
    TEST_ASSERT_FALSE(is_allocated);

    heap_free(heap);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_heap_alloc_should_create_chunk_with_specified_size);
    RUN_TEST(test_heap_alloc_should_not_split_chunks_when_not_enough_memory_for_new_chunk);
    RUN_TEST(test_heap_alloc_should_return_null_if_allocation_exceeds_memory_available);
    RUN_TEST(test_heap_alloc_should_create_new_chunk_out_of_remaining_memory);
    RUN_TEST(test_heap_dealloc_should_remove_allocated_flag);

    return UNITY_END();
}