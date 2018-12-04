#include <stdbool.h>
#include <unity.h>
#include <vm/constants.h>
#include <vm/heap.h>

static char      FILL_CONSTANTS[]      = { 1, 2, 3, 4 };
static int       FILL_CONSTANTS_LENGTH = 4;
static CONSTANTS RANDOM_CONSTANTS;

void set_up()
{
    RANDOM_CONSTANTS.data   = &FILL_CONSTANTS;
    RANDOM_CONSTANTS.length = FILL_CONSTANTS_LENGTH;
}

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

void test_heap_from_constants_should_store_constants_in_first_chunk()
{
    CONSTANTS constants;
    constants.data   = &FILL_CONSTANTS;
    constants.length = FILL_CONSTANTS_LENGTH;

    HEAP  heap              = heap_from(constants, 0);
    char* constants_in_heap = (char*)heap_at(&heap, 0);

    TEST_ASSERT_EQUAL_HEX8(FILL_CONSTANTS[0], constants_in_heap[0]);
    TEST_ASSERT_EQUAL_HEX8(FILL_CONSTANTS[1], constants_in_heap[1]);
    TEST_ASSERT_EQUAL_HEX8(FILL_CONSTANTS[2], constants_in_heap[2]);
    TEST_ASSERT_EQUAL_HEX8(FILL_CONSTANTS[3], constants_in_heap[3]);

    heap_free(heap);
}

void test_heap_from_constants_should_store_in_readonly_chunk()
{
    HEAP   heap            = heap_from(RANDOM_CONSTANTS, 0);
    CHUNK* constants_chunk = (CHUNK*)heap.start;

    bool is_readonly  = (constants_chunk->flags >> CHUNK_FLAGS_READONLY) & 1;
    bool is_allocated = (constants_chunk->flags >> CHUNK_FLAGS_ALLOCATED) & 1;

    TEST_ASSERT_TRUE(is_readonly);
    TEST_ASSERT_TRUE(is_allocated);

    heap_free(heap);
}

void test_heap_should_reserve_memory_after_constants()
{
    int number_of_bytes = 527;

    HEAP   heap         = heap_from(RANDOM_CONSTANTS, number_of_bytes);
    CHUNK* data_chunk   = ((CHUNK*)heap.start)->next;
    bool   is_allocated = (data_chunk->flags >> CHUNK_FLAGS_ALLOCATED) & 1;

    TEST_ASSERT_EQUAL_INT(number_of_bytes, data_chunk->size);
    TEST_ASSERT_FALSE(is_allocated);

    heap_free(heap);
}

void test_heap_ptr_of_first_data_chunk_should_point_after_constants_chunk()
{
    HEAP    heap      = heap_from(RANDOM_CONSTANTS, 0);
    POINTER chunk_ptr = FILL_CONSTANTS_LENGTH + sizeof(CHUNK);

    CHUNK*  data_chunk     = ((CHUNK*)heap.start)->next;
    POINTER data_chunk_ptr = heap_ptr_of_chunk(&heap, data_chunk);
    TEST_ASSERT_EQUAL_UINT32(chunk_ptr, data_chunk_ptr);

    heap_free(heap);
}

void test_heap_alloc_should_create_new_chunk_out_of_remaining_memory()
{
    HEAP heap = heap_from(RANDOM_CONSTANTS, 120);

    heap_alloc(&heap, 60);
    TEST_ASSERT_EQUAL_INT(3, number_of_chunks(heap));

    heap_free(heap);
}

void test_heap_alloc_should_set_allocated_flag()
{
    HEAP heap = heap_from(RANDOM_CONSTANTS, 120);

    POINTER ptr             = heap_alloc(&heap, 60);
    CHUNK*  allocated_chunk = heap_chunk_of_ptr(&heap, ptr);
    bool    is_allocated    = (allocated_chunk->flags >> CHUNK_FLAGS_ALLOCATED) & 1;
    TEST_ASSERT_TRUE(is_allocated);

    heap_free(heap);
}

void test_heap_alloc_should_create_chunk_with_specified_size()
{
    HEAP heap = heap_from(RANDOM_CONSTANTS, 120);

    POINTER ptr = heap_alloc(&heap, 60);

    CHUNK* allocated_chunk = heap_chunk_of_ptr(&heap, ptr);
    TEST_ASSERT_EQUAL_UINT(60, allocated_chunk->size);

    heap_free(heap);
}

void test_heap_alloc_should_not_split_chunks_when_not_enough_memory_for_new_chunk()
{
    int  first_chunk_size = 120;
    HEAP heap             = heap_from(RANDOM_CONSTANTS, first_chunk_size);

    POINTER ptr = heap_alloc(&heap, first_chunk_size);

    TEST_ASSERT_EQUAL_INT(2, number_of_chunks(heap));
    TEST_ASSERT_EQUAL_UINT(first_chunk_size, heap_chunk_of_ptr(&heap, ptr)->size);

    heap_free(heap);
}

void test_heap_alloc_should_return_null_if_allocation_exceeds_memory_available()
{
    int  memory_available = 120;
    HEAP heap             = heap_from(RANDOM_CONSTANTS, memory_available);

    POINTER ptr = heap_alloc(&heap, memory_available + 20);

    TEST_ASSERT_EQUAL_INT(VM_NULL, ptr);

    heap_free(heap);
}

void test_heap_dealloc_should_remove_allocated_flag()
{
    HEAP    heap            = heap_from(RANDOM_CONSTANTS, 120);
    POINTER allocated_ptr   = heap_alloc(&heap, 5);
    CHUNK*  allocated_chunk = heap_chunk_of_ptr(&heap, allocated_ptr);

    heap_dealloc(&heap, allocated_ptr);
    bool is_allocated = (allocated_chunk->flags >> CHUNK_FLAGS_ALLOCATED) & 1;
    TEST_ASSERT_FALSE(is_allocated);

    heap_free(heap);
}

int main(void)
{
    set_up();

    UNITY_BEGIN();
    RUN_TEST(test_heap_should_reserve_memory_after_constants);
    RUN_TEST(test_heap_from_constants_should_store_constants_in_first_chunk);
    RUN_TEST(test_heap_from_constants_should_store_in_readonly_chunk);
    RUN_TEST(test_heap_ptr_of_first_data_chunk_should_point_after_constants_chunk);
    RUN_TEST(test_heap_alloc_should_create_chunk_with_specified_size);
    RUN_TEST(test_heap_alloc_should_not_split_chunks_when_not_enough_memory_for_new_chunk);
    RUN_TEST(test_heap_alloc_should_return_null_if_allocation_exceeds_memory_available);
    RUN_TEST(test_heap_dealloc_should_remove_allocated_flag);
    RUN_TEST(test_heap_alloc_should_set_allocated_flag);

    return UNITY_END();
}