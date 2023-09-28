#include "main.h"

/**
 * factorial - returns the factorial of a number
 * @n: the number
 *
 * Return: -1 if n < 0, else it returns n!
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (1);
	return (n * factorial(n - 1));
}
