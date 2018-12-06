#include <unity.h>
#include <vm/executor.h>
#include <vm/stack.h>

static STACK stack;
static STATE state;

void set_up()
{
    stack = stack_create(10);
}

void before_each()
{
    stack_reset(&stack);
}

void test_ipush_should_push_int_on_top_of_the_stack()
{
    before_each();

    char   bytecode[] = { 0, 15 };
    STREAM program    = stream_create(&bytecode, 2);

    op_ipush(&stack, &program, NULL, state);
    INTEGER int_pushed = stack_pop(&stack).int_val;

    TEST_ASSERT_EQUAL_INT16(15, int_pushed);
}

void test_iadd_should_add_two_ints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_int(10));
    stack_push(&stack, object_of_int(25));
    INTEGER expected_result = 35;

    op_iadd(&stack, NULL, NULL, state);
    INTEGER result = stack_pop(&stack).int_val;

    TEST_ASSERT_EQUAL_INT16(expected_result, result);
}

void test_isub_should_subtract_two_ints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_int(281));
    stack_push(&stack, object_of_int(-238));
    INTEGER expected_result = -519;

    op_isub(&stack, NULL, NULL, state);
    INTEGER result = stack_pop(&stack).int_val;

    TEST_ASSERT_EQUAL_INT16(expected_result, result);
}

void test_idiv_should_divide_two_ints_on_top_of_the_stack() // TODO add test case for division by 0 when exceptions are implemented
{
    before_each();
    stack_push(&stack, object_of_int(5));
    stack_push(&stack, object_of_int(10));
    INTEGER expected_result = 2;

    op_idiv(&stack, NULL, NULL, state);
    INTEGER result = stack_pop(&stack).int_val;

    TEST_ASSERT_EQUAL_INT16(expected_result, result);
}

void test_imul_should_multiply_two_ints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_int(512));
    stack_push(&stack, object_of_int(10));
    INTEGER expected_result = 5120;

    op_imul(&stack, NULL, NULL, state);
    INTEGER result = stack_pop(&stack).int_val;

    TEST_ASSERT_EQUAL_INT16(expected_result, result);
}

void test_iand_should_perform_and_of_two_ints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_int(10));
    stack_push(&stack, object_of_int(25));
    INTEGER expected_result = 8;

    op_iand(&stack, NULL, NULL, state);
    INTEGER result = stack_pop(&stack).int_val;

    TEST_ASSERT_EQUAL_INT16(expected_result, result);
}

void test_ior_should_perform_or_of_two_ints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_int(6));
    stack_push(&stack, object_of_int(32));
    INTEGER expected_result = 38;

    op_ior(&stack, NULL, NULL, state);
    INTEGER result = stack_pop(&stack).int_val;

    TEST_ASSERT_EQUAL_INT16(expected_result, result);
}

void test_ixor_should_perform_xor_of_two_ints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_int(14));
    stack_push(&stack, object_of_int(27));
    INTEGER expected_result = 21;

    op_ixor(&stack, NULL, NULL, state);
    INTEGER result = stack_pop(&stack).int_val;

    TEST_ASSERT_EQUAL_INT16(expected_result, result);
}

void test_inot_should_perform_not_of_int_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_int(480));
    INTEGER expected_result = -481;

    op_inot(&stack, NULL, NULL, state);
    INTEGER result = stack_pop(&stack).int_val;

    TEST_ASSERT_EQUAL_INT16(expected_result, result);
}

void test_ilshift_should_perform_left_shift_of_two_ints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_int(2));
    stack_push(&stack, object_of_int(15));
    INTEGER expected_result = 60;

    op_ilshift(&stack, NULL, NULL, state);
    INTEGER result = stack_pop(&stack).int_val;

    TEST_ASSERT_EQUAL_INT16(expected_result, result);
}

void test_irshift_should_perform_right_shift_of_two_ints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_int(2));
    stack_push(&stack, object_of_int(15));
    INTEGER expected_result = 3;

    op_irshift(&stack, NULL, NULL, state);
    INTEGER result = stack_pop(&stack).int_val;

    TEST_ASSERT_EQUAL_INT16(expected_result, result);
}

void test_uipush_should_push_uint_on_top_of_the_stack()
{
    before_each();

    char   bytecode[] = { 0, 15 };
    STREAM program    = stream_create(&bytecode, 2);

    op_uipush(&stack, &program, NULL, state);
    UINTEGER uint_pushed = stack_pop(&stack).uint_val;

    TEST_ASSERT_EQUAL_UINT16(15, uint_pushed);
}

void test_uiadd_should_add_two_uints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_uint(10));
    stack_push(&stack, object_of_uint(25));
    UINTEGER expected_result = 35;

    op_uiadd(&stack, NULL, NULL, state);
    UINTEGER result = stack_pop(&stack).uint_val;

    TEST_ASSERT_EQUAL_UINT16(expected_result, result);
}

void test_uisub_should_subtract_two_uints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_uint(44));
    stack_push(&stack, object_of_uint(88));
    UINTEGER expected_result = 44;

    op_uisub(&stack, NULL, NULL, state);
    UINTEGER result = stack_pop(&stack).uint_val;

    TEST_ASSERT_EQUAL_UINT16(expected_result, result);
}

void test_uidiv_should_divide_two_uints_on_top_of_the_stack() // TODO add test case for division by 0 when exceptions are implemented
{
    before_each();
    stack_push(&stack, object_of_uint(5));
    stack_push(&stack, object_of_uint(10));
    UINTEGER expected_result = 2;

    op_uidiv(&stack, NULL, NULL, state);
    UINTEGER result = stack_pop(&stack).uint_val;

    TEST_ASSERT_EQUAL_UINT16(expected_result, result);
}

void test_uimul_should_multiply_two_uints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_uint(512));
    stack_push(&stack, object_of_uint(10));
    UINTEGER expected_result = 5120;

    op_uimul(&stack, NULL, NULL, state);
    UINTEGER result = stack_pop(&stack).uint_val;

    TEST_ASSERT_EQUAL_UINT16(expected_result, result);
}

void test_uiand_should_perform_and_of_two_uints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_uint(10));
    stack_push(&stack, object_of_uint(25));
    UINTEGER expected_result = 8;

    op_uiand(&stack, NULL, NULL, state);
    UINTEGER result = stack_pop(&stack).uint_val;

    TEST_ASSERT_EQUAL_UINT16(expected_result, result);
}

void test_uior_should_perform_or_of_two_uints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_uint(6));
    stack_push(&stack, object_of_uint(32));
    UINTEGER expected_result = 38;

    op_uior(&stack, NULL, NULL, state);
    UINTEGER result = stack_pop(&stack).uint_val;

    TEST_ASSERT_EQUAL_UINT16(expected_result, result);
}

void test_uixor_should_perform_xor_of_two_uints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_uint(14));
    stack_push(&stack, object_of_uint(27));
    UINTEGER expected_result = 21;

    op_uixor(&stack, NULL, NULL, state);
    UINTEGER result = stack_pop(&stack).uint_val;

    TEST_ASSERT_EQUAL_UINT16(expected_result, result);
}

void test_uinot_should_perform_not_of_uint_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_uint(480));
    UINTEGER expected_result = -481;

    op_uinot(&stack, NULL, NULL, state);
    UINTEGER result = stack_pop(&stack).uint_val;

    TEST_ASSERT_EQUAL_UINT16(expected_result, result);
}

void test_uilshift_should_perform_left_shift_of_two_uints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_uint(2));
    stack_push(&stack, object_of_uint(15));
    UINTEGER expected_result = 60;

    op_uilshift(&stack, NULL, NULL, state);
    UINTEGER result = stack_pop(&stack).uint_val;

    TEST_ASSERT_EQUAL_UINT16(expected_result, result);
}

void test_uirshift_should_perform_right_shift_of_two_uints_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_uint(2));
    stack_push(&stack, object_of_uint(15));
    UINTEGER expected_result = 3;

    op_uirshift(&stack, NULL, NULL, state);
    UINTEGER result = stack_pop(&stack).uint_val;

    TEST_ASSERT_EQUAL_UINT16(expected_result, result);
}

void test_lpush_should_push_long_on_top_of_the_stack()
{
    before_each();

    char   bytecode[] = { 0, 0, 0, 0, 2, 15, 118, 185 };
    STREAM program    = stream_create(&bytecode, 8);

    op_lpush(&stack, &program, NULL, state);
    LONG long_pushed = stack_pop(&stack).long_val;

    TEST_ASSERT_EQUAL_INT64(34567865, long_pushed);
}

void test_ladd_should_add_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_long(10));
    stack_push(&stack, object_of_long(25));
    LONG expected_result = 35;

    op_ladd(&stack, NULL, NULL, state);
    LONG result = stack_pop(&stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lsub_should_subtract_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_long(45648));
    stack_push(&stack, object_of_long(564864));
    LONG expected_result = 519216;

    op_lsub(&stack, NULL, NULL, state);
    LONG result = stack_pop(&stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_ldiv_should_divide_two_longs_on_top_of_the_stack() // TODO add test case for division by 0 when exceptions are implemented
{
    before_each();
    stack_push(&stack, object_of_long(5));
    stack_push(&stack, object_of_long(10));
    LONG expected_result = 2;

    op_ldiv(&stack, NULL, NULL, state);
    LONG result = stack_pop(&stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lmul_should_multiply_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_long(512));
    stack_push(&stack, object_of_long(10));
    LONG expected_result = 5120;

    op_lmul(&stack, NULL, NULL, state);
    LONG result = stack_pop(&stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_land_should_perform_and_of_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_long(10));
    stack_push(&stack, object_of_long(25));
    LONG expected_result = 8;

    op_land(&stack, NULL, NULL, state);
    LONG result = stack_pop(&stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lor_should_perform_or_of_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_long(6));
    stack_push(&stack, object_of_long(32));
    LONG expected_result = 38;

    op_lor(&stack, NULL, NULL, state);
    LONG result = stack_pop(&stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lxor_should_perform_xor_of_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_long(14));
    stack_push(&stack, object_of_long(27));
    LONG expected_result = 21;

    op_lxor(&stack, NULL, NULL, state);
    LONG result = stack_pop(&stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lnot_should_perform_not_of_long_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_long(480));
    LONG expected_result = -481;

    op_lnot(&stack, NULL, NULL, state);
    LONG result = stack_pop(&stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_llshift_should_perform_left_shift_of_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_long(2));
    stack_push(&stack, object_of_long(15));
    LONG expected_result = 60;

    op_llshift(&stack, NULL, NULL, state);
    LONG result = stack_pop(&stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_lrshift_should_perform_right_shift_of_two_longs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_long(2));
    stack_push(&stack, object_of_long(15));
    LONG expected_result = 3;

    op_lrshift(&stack, NULL, NULL, state);
    LONG result = stack_pop(&stack).long_val;

    TEST_ASSERT_EQUAL_INT64(expected_result, result);
}

void test_ulpush_should_push_ulong_on_top_of_the_stack()
{
    before_each();

    char   bytecode[] = { 0, 0, 0, 0, 2, 15, 118, 185 };
    STREAM program    = stream_create(&bytecode, 8);

    op_lpush(&stack, &program, NULL, state);
    ULONG ulong_pushed = stack_pop(&stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(34567865, ulong_pushed);
}

void test_uladd_should_add_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_ulong(10));
    stack_push(&stack, object_of_ulong(25));
    ULONG expected_result = 35;

    op_ladd(&stack, NULL, NULL, state);
    ULONG result = stack_pop(&stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulsub_should_subtract_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_ulong(45648));
    stack_push(&stack, object_of_ulong(564864));
    ULONG expected_result = 519216;

    op_lsub(&stack, NULL, NULL, state);
    ULONG result = stack_pop(&stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_uldiv_should_divide_two_ulongs_on_top_of_the_stack() // TODO add test case for division by 0 when exceptions are implemented
{
    before_each();
    stack_push(&stack, object_of_ulong(5));
    stack_push(&stack, object_of_ulong(10));
    ULONG expected_result = 2;

    op_ldiv(&stack, NULL, NULL, state);
    ULONG result = stack_pop(&stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulmul_should_multiply_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_ulong(512));
    stack_push(&stack, object_of_ulong(10));
    ULONG expected_result = 5120;

    op_lmul(&stack, NULL, NULL, state);
    ULONG result = stack_pop(&stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_uland_should_perform_and_of_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_ulong(10));
    stack_push(&stack, object_of_ulong(25));
    ULONG expected_result = 8;

    op_land(&stack, NULL, NULL, state);
    ULONG result = stack_pop(&stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulor_should_perform_or_of_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_ulong(6));
    stack_push(&stack, object_of_ulong(32));
    ULONG expected_result = 38;

    op_lor(&stack, NULL, NULL, state);
    ULONG result = stack_pop(&stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulxor_should_perform_xor_of_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_ulong(14));
    stack_push(&stack, object_of_ulong(27));
    ULONG expected_result = 21;

    op_lxor(&stack, NULL, NULL, state);
    ULONG result = stack_pop(&stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulnot_should_perform_not_of_ulong_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_ulong(480));
    ULONG expected_result = -481;

    op_lnot(&stack, NULL, NULL, state);
    ULONG result = stack_pop(&stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ullshift_should_perform_left_shift_of_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_ulong(2));
    stack_push(&stack, object_of_ulong(15));
    ULONG expected_result = 60;

    op_llshift(&stack, NULL, NULL, state);
    ULONG result = stack_pop(&stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

void test_ulrshift_should_perform_right_shift_of_two_ulongs_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_ulong(2));
    stack_push(&stack, object_of_ulong(15));
    ULONG expected_result = 3;

    op_lrshift(&stack, NULL, NULL, state);
    ULONG result = stack_pop(&stack).ulong_val;

    TEST_ASSERT_EQUAL_UINT64(expected_result, result);
}

int main(void)
{
    set_up();
    UNITY_BEGIN();
    RUN_TEST(test_ipush_should_push_int_on_top_of_the_stack);
    RUN_TEST(test_iadd_should_add_two_ints_on_top_of_the_stack);
    RUN_TEST(test_isub_should_subtract_two_ints_on_top_of_the_stack);
    RUN_TEST(test_idiv_should_divide_two_ints_on_top_of_the_stack);
    RUN_TEST(test_imul_should_multiply_two_ints_on_top_of_the_stack);
    RUN_TEST(test_iand_should_perform_and_of_two_ints_on_top_of_the_stack);
    RUN_TEST(test_ior_should_perform_or_of_two_ints_on_top_of_the_stack);
    RUN_TEST(test_ixor_should_perform_xor_of_two_ints_on_top_of_the_stack);
    RUN_TEST(test_inot_should_perform_not_of_int_on_top_of_the_stack);
    RUN_TEST(test_ilshift_should_perform_left_shift_of_two_ints_on_top_of_the_stack);
    RUN_TEST(test_irshift_should_perform_right_shift_of_two_ints_on_top_of_the_stack);

    RUN_TEST(test_uipush_should_push_uint_on_top_of_the_stack);
    RUN_TEST(test_uiadd_should_add_two_uints_on_top_of_the_stack);
    RUN_TEST(test_uisub_should_subtract_two_uints_on_top_of_the_stack);
    RUN_TEST(test_uidiv_should_divide_two_uints_on_top_of_the_stack);
    RUN_TEST(test_uimul_should_multiply_two_uints_on_top_of_the_stack);
    RUN_TEST(test_uiand_should_perform_and_of_two_uints_on_top_of_the_stack);
    RUN_TEST(test_uior_should_perform_or_of_two_uints_on_top_of_the_stack);
    RUN_TEST(test_uixor_should_perform_xor_of_two_uints_on_top_of_the_stack);
    RUN_TEST(test_uinot_should_perform_not_of_uint_on_top_of_the_stack);
    RUN_TEST(test_uilshift_should_perform_left_shift_of_two_uints_on_top_of_the_stack);
    RUN_TEST(test_uirshift_should_perform_right_shift_of_two_uints_on_top_of_the_stack);

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