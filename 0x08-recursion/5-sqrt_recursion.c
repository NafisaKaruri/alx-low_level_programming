#include "main.h"

/**
 * square - finds the square of an int
 * @n: the number
 * @val: the square root
 *
 * Return: the square root
 */
int square(int n, int val)
{
	if (val * val == n)
		return (val);
	else if (val * val < n)
		return (square(n, val + 1));
	else
		return (-1);
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number
 *
 * Return: -1 if n doesn't have a natural square root,
 *		else returns the natural square root of n
 */
int _sqrt_recursion(int n)
{
	if (n == 0 || n == 1)
		return (n);
	else if (n < 0)
		return (-1);
	return (square(n, 1));
}
