#include <unity.h>
#include <vm/math.h>
#include <vm/type.h>

void test_int_to_big_endian()
{
    INTEGER small_endian        = 0x1234;
    INTEGER expected_big_endian = 0x3412;

    INTEGER big_endian = math_int_to_big_endian(small_endian);

    TEST_ASSERT_EQUAL_INT16(expected_big_endian, big_endian);
}

void test_long_to_big_endian()
{
    LONG    small_endian                = 0x1234567890123456;
    POINTER expected_big_endian_block_1 = 0x56341290;
    POINTER expected_big_endian_block_2 = 0x78563412;

    LONG big_endian = math_long_to_big_endian(small_endian);
    // Dirty hack: Enabling 64 bit support in unity (for TEST_ASSERT_EQUAL_INT64) causes segfaults when using any other assertion after!
    POINTER block_1 = (big_endian & 0xffffffff00000000) >> 32;
    POINTER block_2 = big_endian & 0xffffffff;

    TEST_ASSERT_EQUAL_INT32(expected_big_endian_block_1, block_1);
    TEST_ASSERT_EQUAL_INT32(expected_big_endian_block_2, block_2);
}

void test_ptr_to_big_endian()
{
    POINTER small_endian        = 0x12345678;
    POINTER expected_big_endian = 0x78563412;

    POINTER big_endian = math_ptr_to_big_endian(small_endian);

    TEST_ASSERT_EQUAL_UINT32(expected_big_endian, big_endian);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_int_to_big_endian);
    RUN_TEST(test_long_to_big_endian);
    RUN_TEST(test_ptr_to_big_endian);
    return UNITY_END();
}