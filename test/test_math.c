#include <stdint.h>
#include <unity.h>
#include <vm/math.h>

void test_int16_endian_swap()
{
    int32_t small_endian        = 0x1234;
    int32_t expected_big_endian = 0x3412;

    int32_t big_endian = math_int16_endian_swap(small_endian);

    TEST_ASSERT_EQUAL_INT16(expected_big_endian, big_endian);
}

void test_int64_endian_swap()
{
    int64_t small_endian                = 0x1234567890123456;
    int32_t expected_big_endian_block_1 = 0x56341290;
    int32_t expected_big_endian_block_2 = 0x78563412;

    int64_t big_endian = math_int64_endian_swap(small_endian);
    // Dirty hack: Enabling 64 bit support in unity (for TEST_ASSERT_EQUAL_INT64) causes segfaults when using any other assertion after!
    int32_t block_1 = (big_endian & 0xffffffff00000000) >> 32;
    int32_t block_2 = big_endian & 0xffffffff;

    TEST_ASSERT_EQUAL_INT32(expected_big_endian_block_1, block_1);
    TEST_ASSERT_EQUAL_INT32(expected_big_endian_block_2, block_2);
}

void test_int32_endian_swap()
{
    int32_t small_endian        = 0x12345678;
    int32_t expected_big_endian = 0x78563412;

    int32_t big_endian = math_int32_endian_swap(small_endian);

    TEST_ASSERT_EQUAL_UINT32(expected_big_endian, big_endian);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_int16_endian_swap);
    RUN_TEST(test_int64_endian_swap);
    RUN_TEST(test_int32_endian_swap);
    return UNITY_END();
}