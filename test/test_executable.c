#include <unity.h>
#include <vm/executable.h>

char stream_advance_char(STREAM* program)
{
    return *((char*)stream_advance(program, sizeof(char)));
}

void test_executable_header_should_parse_executable_length()
{
    char executable[] = {
        0, 0, 0, 0, 0, 0, 0, 12, // Executable length
        0, 0, 0, 0, 0, 0, 0, 0, // Constants length
        0 // Program
    };
    STREAM s = stream_create(&executable);

    EXECUTABLE_HEADER header = executable_read_header(&s);

    TEST_ASSERT_EQUAL_UINT64(12, header.executable_length);
}

void test_executable_header_should_parse_constants_length()
{
    char executable[] = {
        0, 0, 0, 0, 0, 0, 0, 12, // Executable length
        0, 0, 0, 0, 0, 0, 0, 241, // Constants length
        0 // Program
    };
    STREAM s = stream_create(&executable);

    EXECUTABLE_HEADER header = executable_read_header(&s);

    TEST_ASSERT_EQUAL_UINT64(241, header.constants_length);
}

void test_executable_should_copy_constants()
{
    char executable[] = {
        0, 0, 0, 0, 0, 0, 0, 21, // Executable length
        0, 0, 0, 0, 0, 0, 0, 4, // Constants length
        1, 2, 3, 4, // Constants
        0 // Program
    };

    EXECUTABLE parsed_executable = executable_from(&executable);
    char*      parsed_constants  = (char*)parsed_executable.constants;

    TEST_ASSERT_EQUAL_UINT8(1, parsed_constants[0]);
    TEST_ASSERT_EQUAL_UINT8(2, parsed_constants[1]);
    TEST_ASSERT_EQUAL_UINT8(3, parsed_constants[2]);
    TEST_ASSERT_EQUAL_UINT8(4, parsed_constants[3]);
    TEST_ASSERT_EQUAL_UINT64(parsed_executable.constants_length, 4);

    executable_free(parsed_executable);
}

void test_executable_should_copy_program()
{
    char executable[] = {
        0, 0, 0, 0, 0, 0, 0, 20, // Executable length
        0, 0, 0, 0, 0, 0, 0, 0, // Constants length
        10, 20, 30, 40 // Program
    };

    EXECUTABLE parsed_executable = executable_from(&executable);

    TEST_ASSERT_EQUAL_UINT8(10, stream_advance_char(&parsed_executable.program));
    TEST_ASSERT_EQUAL_UINT8(20, stream_advance_char(&parsed_executable.program));
    TEST_ASSERT_EQUAL_UINT8(30, stream_advance_char(&parsed_executable.program));
    TEST_ASSERT_EQUAL_UINT8(40, stream_advance_char(&parsed_executable.program));

    executable_free(parsed_executable);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_executable_header_should_parse_constants_length);
    RUN_TEST(test_executable_header_should_parse_executable_length);
    RUN_TEST(test_executable_should_copy_constants);
    RUN_TEST(test_executable_should_copy_program);

    return UNITY_END();
}