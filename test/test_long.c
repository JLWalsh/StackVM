#include <unity.h>
#include <vm/long.h>
#include <vm/stack.h>
#include <vm/vm.h>

static VM vm;

void set_up()
{
    vm.stack = stack_create(10);
}

void before_each()
{
    stack_reset(&vm.stack);
}

void test_lpush_should_push_long_on_top_of_the_stack()
{
    before_each();

    char   bytecode[] = { 0, 0, 0, 0, 2, 15, 118, 185 };
    STREAM program    = stream_create(&bytecode);
    vm.program        = program;

    op_lpush(&vm);
    LONG long_pushed = stack_pop(&vm.stack).long_val;

    TEST_ASSERT_EQUAL_INT64(34567865, long_pushed);
}

void test_ladd_should_add_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_long(10));
    stack_push(&vm.stack, object_of_long(25));
    LONG expected_result = 35;

    op_ladd(&vm);
    LONG result = stack_pop(&vm.stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lsub_should_subtract_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_long(45648));
    stack_push(&vm.stack, object_of_long(564864));
    LONG expected_result = 519216;

    op_lsub(&vm);
    LONG result = stack_pop(&vm.stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_ldiv_should_divide_two_longs_on_top_of_the_stack() // TODO add test case for division by 0 when exceptions are implemented
{
    before_each();
    stack_push(&vm.stack, object_of_long(5));
    stack_push(&vm.stack, object_of_long(10));
    LONG expected_result = 2;

    op_ldiv(&vm);
    LONG result = stack_pop(&vm.stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lmul_should_multiply_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_long(512));
    stack_push(&vm.stack, object_of_long(10));
    LONG expected_result = 5120;

    op_lmul(&vm);
    LONG result = stack_pop(&vm.stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_land_should_perform_and_of_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_long(10));
    stack_push(&vm.stack, object_of_long(25));
    LONG expected_result = 8;

    op_land(&vm);
    LONG result = stack_pop(&vm.stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lor_should_perform_or_of_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_long(6));
    stack_push(&vm.stack, object_of_long(32));
    LONG expected_result = 38;

    op_lor(&vm);
    LONG result = stack_pop(&vm.stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lxor_should_perform_xor_of_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_long(14));
    stack_push(&vm.stack, object_of_long(27));
    LONG expected_result = 21;

    op_lxor(&vm);
    LONG result = stack_pop(&vm.stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lnot_should_perform_not_of_long_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_long(480));
    LONG expected_result = -481;

    op_lnot(&vm);
    LONG result = stack_pop(&vm.stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_llshift_should_perform_left_shift_of_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_long(2));
    stack_push(&vm.stack, object_of_long(15));
    LONG expected_result = 60;

    op_llshift(&vm);
    LONG result = stack_pop(&vm.stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lrshift_should_perform_right_shift_of_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_long(2));
    stack_push(&vm.stack, object_of_long(15));
    LONG expected_result = 3;

    op_lrshift(&vm);
    LONG result = stack_pop(&vm.stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_ulpush_should_push_ulong_on_top_of_the_stack()
{
    before_each();

    char   bytecode[] = { 0, 0, 0, 0, 2, 15, 118, 185 };
    STREAM program    = stream_create(&bytecode);
    vm.program        = program;

    op_lpush(&vm);
    ULONG ulong_pushed = stack_pop(&vm.stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(34567865, ulong_pushed);
}

void test_uladd_should_add_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_ulong(10));
    stack_push(&vm.stack, object_of_ulong(25));
    ULONG expected_result = 35;

    op_ladd(&vm);
    ULONG result = stack_pop(&vm.stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulsub_should_subtract_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_ulong(45648));
    stack_push(&vm.stack, object_of_ulong(564864));
    ULONG expected_result = 519216;

    op_lsub(&vm);
    ULONG result = stack_pop(&vm.stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_uldiv_should_divide_two_ulongs_on_top_of_the_stack() // TODO add test case for division by 0 when exceptions are implemented
{
    before_each();
    stack_push(&vm.stack, object_of_ulong(5));
    stack_push(&vm.stack, object_of_ulong(10));
    ULONG expected_result = 2;

    op_ldiv(&vm);
    ULONG result = stack_pop(&vm.stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulmul_should_multiply_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_ulong(512));
    stack_push(&vm.stack, object_of_ulong(10));
    ULONG expected_result = 5120;

    op_lmul(&vm);
    ULONG result = stack_pop(&vm.stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_uland_should_perform_and_of_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_ulong(10));
    stack_push(&vm.stack, object_of_ulong(25));
    ULONG expected_result = 8;

    op_land(&vm);
    ULONG result = stack_pop(&vm.stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulor_should_perform_or_of_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_ulong(6));
    stack_push(&vm.stack, object_of_ulong(32));
    ULONG expected_result = 38;

    op_lor(&vm);
    ULONG result = stack_pop(&vm.stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulxor_should_perform_xor_of_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_ulong(14));
    stack_push(&vm.stack, object_of_ulong(27));
    ULONG expected_result = 21;

    op_lxor(&vm);
    ULONG result = stack_pop(&vm.stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulnot_should_perform_not_of_ulong_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_ulong(480));
    ULONG expected_result = -481;

    op_lnot(&vm);
    ULONG result = stack_pop(&vm.stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ullshift_should_perform_left_shift_of_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_ulong(2));
    stack_push(&vm.stack, object_of_ulong(15));
    ULONG expected_result = 60;

    op_llshift(&vm);
    ULONG result = stack_pop(&vm.stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulrshift_should_perform_right_shift_of_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&vm.stack, object_of_ulong(2));
    stack_push(&vm.stack, object_of_ulong(15));
    ULONG expected_result = 3;

    op_lrshift(&vm);
    ULONG result = stack_pop(&vm.stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

int main(void)
{
    set_up();
    UNITY_BEGIN();
    RUN_TEST(test_lpush_should_push_long_on_top_of_the_stack);
    RUN_TEST(test_ladd_should_add_two_longs_on_top_of_the_stack);
    RUN_TEST(test_lsub_should_subtract_two_longs_on_top_of_the_stack);
    RUN_TEST(test_ldiv_should_divide_two_longs_on_top_of_the_stack);
    RUN_TEST(test_lmul_should_multiply_two_longs_on_top_of_the_stack);
    RUN_TEST(test_land_should_perform_and_of_two_longs_on_top_of_the_stack);
    RUN_TEST(test_lor_should_perform_or_of_two_longs_on_top_of_the_stack);
    RUN_TEST(test_lxor_should_perform_xor_of_two_longs_on_top_of_the_stack);
    RUN_TEST(test_lnot_should_perform_not_of_long_on_top_of_the_stack);
    RUN_TEST(test_llshift_should_perform_left_shift_of_two_longs_on_top_of_the_stack);
    RUN_TEST(test_lrshift_should_perform_right_shift_of_two_longs_on_top_of_the_stack);

    RUN_TEST(test_ulpush_should_push_ulong_on_top_of_the_stack);
    RUN_TEST(test_uladd_should_add_two_ulongs_on_top_of_the_stack);
    RUN_TEST(test_ulsub_should_subtract_two_ulongs_on_top_of_the_stack);
    RUN_TEST(test_uldiv_should_divide_two_ulongs_on_top_of_the_stack);
    RUN_TEST(test_ulmul_should_multiply_two_ulongs_on_top_of_the_stack);
    RUN_TEST(test_uland_should_perform_and_of_two_ulongs_on_top_of_the_stack);
    RUN_TEST(test_ulor_should_perform_or_of_two_ulongs_on_top_of_the_stack);
    RUN_TEST(test_ulxor_should_perform_xor_of_two_ulongs_on_top_of_the_stack);
    RUN_TEST(test_ulnot_should_perform_not_of_ulong_on_top_of_the_stack);
    RUN_TEST(test_ullshift_should_perform_left_shift_of_two_ulongs_on_top_of_the_stack);
    RUN_TEST(test_ulrshift_should_perform_right_shift_of_two_ulongs_on_top_of_the_stack);

    return UNITY_END();
}