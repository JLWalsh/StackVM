#include <unity.h>
#include <vm/float.h>
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

void test_fpush_should_push_float_on_top_of_the_stack()
{
    before_each();

    char   bytecode[] = { 195, 163, 29, 188 };
    STREAM program    = stream_create(&bytecode, 8);

    op_fpush(&stack, &program, NULL, state);
    float float_pushed = stack_pop(&stack).float_val;

    TEST_ASSERT_EQUAL_UINT64(-326.2323, float_pushed);
}

void test_fadd_should_add_two_floats_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_float(10.239));
    stack_push(&stack, object_of_float(-381.3));
    float expected_result = -371.061;

    op_fadd(&stack, NULL, NULL, state);
    float result = stack_pop(&stack).float_val;

    TEST_ASSERT_EQUAL_FLOAT(expected_result, result);
}

void test_fsub_should_subtract_two_floats_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_float(991.313));
    stack_push(&stack, object_of_float(2381.23));
    float expected_result = 1389.917;

    op_fsub(&stack, NULL, NULL, state);
    float result = stack_pop(&stack).float_val;

    TEST_ASSERT_EQUAL_FLOAT(expected_result, result);
}

void test_fdiv_should_divide_two_floats_on_top_of_the_stack() // TODO add test case for division by 0 when exceptions are implemented
{
    before_each();
    stack_push(&stack, object_of_float(2));
    stack_push(&stack, object_of_float(23.82));
    float expected_result = 11.91;

    op_fdiv(&stack, NULL, NULL, state);
    float result = stack_pop(&stack).float_val;

    TEST_ASSERT_EQUAL_FLOAT(expected_result, result);
}

void test_fmul_should_multiply_two_floats_on_top_of_the_stack()
{
    before_each();
    stack_push(&stack, object_of_float(512.83));
    stack_push(&stack, object_of_float(-193.35));
    float expected_result = -99155.6805;

    op_fmul(&stack, NULL, NULL, state);
    float result = stack_pop(&stack).float_val;

    TEST_ASSERT_EQUAL_FLOAT(expected_result, result);
}

int main(void)
{
    set_up();
    UNITY_BEGIN();
    RUN_TEST(test_fpush_should_push_float_on_top_of_the_stack);
    RUN_TEST(test_fadd_should_add_two_floats_on_top_of_the_stack);
    RUN_TEST(test_fsub_should_subtract_two_floats_on_top_of_the_stack);
    RUN_TEST(test_fdiv_should_divide_two_floats_on_top_of_the_stack);
    RUN_TEST(test_fmul_should_multiply_two_floats_on_top_of_the_stack);

    return UNITY_END();
}