#include <unity.h>
#include <vm/constants.h>
#include <vm/heap.h>

static char FILL_CONSTANTS[]      = { 1, 2, 3, 4 };
static int  FILL_CONSTANTS_LENGTH = 4;

void test_heap_from_constants_should_include_constants()
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
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_heap_from_constants_should_include_constants);
    return UNITY_END();
}