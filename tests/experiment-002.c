#include <stdio.h>
#include "parser.h"

/* Test helper macros */
#define TEST_PASS(name) printf("PASS: %s\n", name)
#define TEST_FAIL(name, msg) printf("FAIL: %s - %s\n", name, msg)

/* Test cases */
static int
test_valid_integer(void)
{
	const char     *input = "123";
	if (parser_ParseInteger(input) != 0) {
		TEST_FAIL("valid_integer", "Failed to parse valid integer");
		return 1;
	}
	TEST_PASS("valid_integer");
	return 0;
}

static int
test_valid_float(void)
{
	const char     *input = "123.456";
	if (parser_ParseFloat(input) != 0) {
		TEST_FAIL("valid_float", "Failed to parse valid float");
		return 1;
	}
	TEST_PASS("valid_float");
	return 0;
}

static int
test_valid_string(void)
{
	const char     *input = "\"hello world\"";
	if (parser_ParseString(input) != 0) {
		TEST_FAIL("valid_string", "Failed to parse valid string");
		return 1;
	}
	TEST_PASS("valid_string");
	return 0;
}

static int
test_invalid_float_no_decimal(void)
{
	const char     *input = "123.";
	if (parser_ParseFloat(input) == 0) {
		TEST_FAIL("invalid_float_no_decimal", "Should fail on missing decimal part");
		return 1;
	}
	TEST_PASS("invalid_float_no_decimal");
	return 0;
}

static int
test_invalid_float_no_integer(void)
{
	const char     *input = ".456";
	if (parser_ParseFloat(input) == 0) {
		TEST_FAIL("invalid_float_no_integer", "Should fail on missing integer part");
		return 1;
	}
	TEST_PASS("invalid_float_no_integer");
	return 0;
}

static int
test_unterminated_string(void)
{
	const char     *input = "\"unterminated";
	if (parser_ParseString(input) == 0) {
		TEST_FAIL("unterminated_string", "Should fail on unterminated string");
		return 1;
	}
	TEST_PASS("unterminated_string");
	return 0;
}

int
main(void)
{
	int		failed = 0;

	/* Run all tests */
	failed += test_valid_integer();
	failed += test_valid_float();
	failed += test_valid_string();
	failed += test_invalid_float_no_decimal();
	failed += test_invalid_float_no_integer();
	failed += test_unterminated_string();

	/* Summary */
	if (failed == 0) {
		printf("\nAll tests passed!\n");
		return 0;
	} else {
		printf("\n%d test(s) failed!\n", failed);
		return 1;
	}
}
