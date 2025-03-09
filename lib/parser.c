#include "parser.h"

/* Helper function to check if a character is a digit */
static int
is_digit(char c)
{
	return c >= '0' && c <= '9';
}

/* Helper function to validate and advance through digits */
static int
consume_digits(const char **input)
{
	int		found_digit = 0;

	while (is_digit(**input)) {
		found_digit = 1;
		(*input)++;
	}

	return found_digit;
}

int
parser_ParseInteger(const char *input)
{
	if (input == 0 || *input == '\0') {
		return 1;
	}

	/* Must have at least one digit */
	return !consume_digits(&input);
}

int
parser_ParseFloat(const char *input)
{
	int		has_integer_part;
	int		has_decimal_part;

	if (input == 0 || *input == '\0') {
		return 1;
	}

	/* Parse integer part */
	has_integer_part = consume_digits(&input);

	/* Must have a decimal point */
	if (*input != '.') {
		return 1;
	}
	input++;

	/* Parse decimal part */
	has_decimal_part = consume_digits(&input);

	/* Both parts must exist */
	return !(has_integer_part && has_decimal_part);
}

int
parser_ParseString(const char *input)
{
	if (input == 0 || *input == '\0') {
		return 1;
	}

	/* Must start with quote */
	if (*input != '"') {
		return 1;
	}
	input++;

	/* Consume everything until closing quote */
	while (*input != '\0' && *input != '"') {
		input++;
	}

	/* Must end with quote */
	return *input != '"';
}
