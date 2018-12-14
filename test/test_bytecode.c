#include <unity.h>
#include <vm/bytecode.h>

static int64_t RANDOM_NUMBERS = 0x1234567890123456;
static VM      vm;

void set_up()
{
    vm.program = stream_create(&RANDOM_NUMBERS);
}

void before_each()
{
    stream_seek(&vm.program, 0);
}

void test_bytecode_when_read_integer_should_read_correct_amount_of_bits()
{
    before_each();
    POINTER expected_pos = 2;

    bytecode_read_int(&vm);
    POINTER position = stream_position(&vm.program);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_uinteger_should_read_correct_amount_of_bits()
{
    before_each();
    POINTER expected_pos = 2;

    bytecode_read_uint(&vm);
    POINTER position = stream_position(&vm.program);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_long_should_read_correct_amount_of_bits()
{
    before_each();
    POINTER expected_pos = 8;

    bytecode_read_long(&vm);
    POINTER position = stream_position(&vm.program);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_ulong_should_read_correct_amount_of_bits()
{
    before_each();
    POINTER expected_pos = 8;

    bytecode_read_ulong(&vm);
    POINTER position = stream_position(&vm.program);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_ptr_should_read_correct_amount_ofbits()
{
    before_each();
    POINTER expected_pos = 4;

    bytecode_read_ptr(&vm);
    POINTER position = stream_position(&vm.program);

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