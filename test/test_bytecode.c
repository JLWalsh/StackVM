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

void test_bytecode_when_read_integer_should_update_instruction_pointer()
{
    before_each();
    POINTER expected_pos = 2;

    bytecode_program_read_int(&vm);
    POINTER position = stream_position(&vm.program);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_uinteger_should_update_instruction_pointer()
{
    before_each();
    POINTER expected_pos = 2;

    bytecode_program_read_uint(&vm);
    POINTER position = stream_position(&vm.program);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_long_should_update_instruction_pointer()
{
    before_each();
    POINTER expected_pos = 8;

    bytecode_program_read_long(&vm);
    POINTER position = stream_position(&vm.program);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_ulong_should_update_instruction_pointer()
{
    before_each();
    POINTER expected_pos = 8;

    bytecode_program_read_ulong(&vm);
    POINTER position = stream_position(&vm.program);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_ptr_should_update_instruction_pointer()
{
    before_each();
    POINTER expected_pos = 4;

    bytecode_program_read_ptr(&vm);
    POINTER position = stream_position(&vm.program);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_when_read_float_should_update_instruction_pointer()
{
    before_each();
    POINTER expected_pos = 4;

    bytecode_program_read_float(&vm);
    POINTER position = stream_position(&vm.program);

    TEST_ASSERT_EQUAL_INT32(expected_pos, position);
}

void test_bytecode_should_read_int()
{
    char   bytes[]  = { 0, 22 };
    STREAM bytecode = stream_create(&bytes);

    INTEGER value = bytecode_read_int(&bytecode);

    TEST_ASSERT_EQUAL_INT16(22, value);
}

void test_bytecode_should_read_uint()
{
    char   bytes[]  = { 0, 244 };
    STREAM bytecode = stream_create(&bytes);

    UINTEGER value = bytecode_read_uint(&bytecode);

    TEST_ASSERT_EQUAL_UINT16(244, value);
}

void test_bytecode_should_read_opcode()
{
    char   bytes[]  = { 0, 18 };
    STREAM bytecode = stream_create(&bytes);

    OPCODE value = bytecode_read_opcode(&bytecode);

    TEST_ASSERT_EQUAL_UINT16(18, value);
}

void test_bytecode_should_read_ptr()
{
    char   bytes[]  = { 0, 0, 0, 28 };
    STREAM bytecode = stream_create(&bytes);

    POINTER value = bytecode_read_ptr(&bytecode);

    TEST_ASSERT_EQUAL_UINT32(28, value);
}

void test_bytecode_should_read_long()
{
    char   bytes[]  = { 0, 0, 0, 0, 0, 0, 0, 52 };
    STREAM bytecode = stream_create(&bytes);

    LONG value = bytecode_read_long(&bytecode);

    TEST_ASSERT_EQUAL_INT64(52, value);
}

void test_bytecode_should_read_ulong()
{
    char   bytes[]  = { 0, 0, 0, 0, 0, 0, 0, 42 };
    STREAM bytecode = stream_create(&bytes);

    ULONG value = bytecode_read_ulong(&bytecode);

    TEST_ASSERT_EQUAL_UINT64(42, value);
}

void test_bytecode_should_read_float()
{
    char   bytes[]  = { 248, 211, 41, 66 };
    STREAM bytecode = stream_create(&bytes);

    float value = bytecode_read_float(&bytecode);

    TEST_ASSERT_EQUAL_FLOAT(42.457, value);
}

int main(void)
{
    set_up();
    UNITY_BEGIN();
    RUN_TEST(test_bytecode_when_read_integer_should_update_instruction_pointer);
    RUN_TEST(test_bytecode_when_read_uinteger_should_update_instruction_pointer);
    RUN_TEST(test_bytecode_when_read_long_should_update_instruction_pointer);
    RUN_TEST(test_bytecode_when_read_ulong_should_update_instruction_pointer);
    RUN_TEST(test_bytecode_when_read_ptr_should_update_instruction_pointer);

    RUN_TEST(test_bytecode_should_read_int);
    RUN_TEST(test_bytecode_should_read_uint);
    RUN_TEST(test_bytecode_should_read_opcode);
    RUN_TEST(test_bytecode_should_read_ptr);
    RUN_TEST(test_bytecode_should_read_long);
    RUN_TEST(test_bytecode_should_read_ulong);
    RUN_TEST(test_bytecode_should_read_float);

    return UNITY_END();
}