#include <unity.h>
#include <vm/bytecode.h>

static int64_t RANDOM_NUMBERS = 0x1234567890123456;
static STREAM  PROGRAM_OF_RANDOM_NUMBERS;

void set_up()
{
    PROGRAM_OF_RANDOM_NUMBERS = stream_create(&RANDOM_NUMBERS, 8);
}

void before_each()
{
    stream_seek(&PROGRAM_OF_RANDOM_NUMBERS, 0);
}

void test_bytecode_when_read_integer_should_read_correct_amount_of_bits()
{
    before_each();
    POINTER expected_pos = 2;

    bytecode_read_int(&PROGRAM_OF_RANDOM_NUMBERS);
    POINTER position = stream_position(&PROGRAM_OF_RANDOM_NUMBERS);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_uinteger_should_read_correct_amount_of_bits()
{
    before_each();
    POINTER expected_pos = 2;

    bytecode_read_uint(&PROGRAM_OF_RANDOM_NUMBERS);
    POINTER position = stream_position(&PROGRAM_OF_RANDOM_NUMBERS);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_long_should_read_correct_amount_of_bits()
{
    before_each();
    POINTER expected_pos = 8;

    bytecode_read_long(&PROGRAM_OF_RANDOM_NUMBERS);
    POINTER position = stream_position(&PROGRAM_OF_RANDOM_NUMBERS);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_ulong_should_read_correct_amount_of_bits()
{
    before_each();
    POINTER expected_pos = 8;

    bytecode_read_ulong(&PROGRAM_OF_RANDOM_NUMBERS);
    POINTER position = stream_position(&PROGRAM_OF_RANDOM_NUMBERS);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_ptr_should_read_correct_amount_ofbits()
{
    before_each();
    POINTER expected_pos = 4;

    bytecode_read_ptr(&PROGRAM_OF_RANDOM_NUMBERS);
    POINTER position = stream_position(&PROGRAM_OF_RANDOM_NUMBERS);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

int main(void)
{
    set_up();
    UNITY_BEGIN();
    RUN_TEST(test_bytecode_when_read_integer_should_read_correct_amount_of_bits);
    RUN_TEST(test_bytecode_when_read_uinteger_should_read_correct_amount_of_bits);
    RUN_TEST(test_bytecode_when_read_long_should_read_correct_amount_of_bits);
    RUN_TEST(test_bytecode_when_read_ulong_should_read_correct_amount_of_bits);
    RUN_TEST(test_bytecode_when_read_ptr_should_read_correct_amount_ofbits);
    return UNITY_END();
}