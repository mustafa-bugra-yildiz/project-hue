#include "hue.h"
#include "parser.h"

const char *
hello(void)
{
	return "hello world";
}

int
parse_integer(const char *input)
{
	return parser_ParseInteger(input);
}

int
parse_float(const char *input)
{
	return parser_ParseFloat(input);
}

int
parse_string(const char *input)
{
	return parser_ParseString(input);
}
