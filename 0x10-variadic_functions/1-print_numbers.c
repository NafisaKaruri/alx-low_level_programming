#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_numbers - prints numbers followed by a new line
 * @separator: the string to be printed between numbers
 * @n: the number of integers passed to the function
 * ...: the integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	if (separator != NULL)
	{
		va_list ap;
		unsigned int i;

		va_start(ap, n);
		for (i = 0; i < n; i++)
		{
			printf("%d", va_arg(ap, int));
			if (i < n - 1)
				printf("%s", separator);
		}
		va_end(ap);
		printf("\n");
	}
}