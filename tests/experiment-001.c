#include <string.h>
#include <stdio.h>
#include "hue.h"

int
main(void)
{
	const char     *expected = "hello world";
	const char     *result = hello();

	if (strcmp(result, expected) != 0) {
		printf("Test failed!\n");
		printf("Expected: '%s'\n", expected);
		printf("Got: '%s'\n", result);
		return 1;
	}

	printf("Test passed!\n");
	return 0;
}
