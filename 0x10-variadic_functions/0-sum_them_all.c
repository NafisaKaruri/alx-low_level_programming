#include "variadic_functions.h"

/**
 * sum_them_all - sum all its parameters
 * @n: the number of parameters
 * ...: parameters
 *
 * Return: 0 if n == 0, otherwise return sum
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	int sum = 0;

	va_start(ap, n);
	if (n == 0)
		return (0);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(ap, int);
	}
	va_end(ap);
	return (sum);
}
