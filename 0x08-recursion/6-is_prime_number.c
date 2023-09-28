#include "main.h"

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

/**
 * prime - checks if a number is prime
 * @n: the number
 * @val: the number to check if n is divisible by
 *
 * Return: 1 if n is prime, otherwise return 0
 */
int prime(int n, int val)
{
	if (val > _sqrt_recursion(n))
		return (1);
	if (n % val == 0)
		return (0);
	return (prime(n, val + 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: the number
 *
 * Return: 1 if n is prime, otherwise return 0
 */
int is_prime_number(int n)
{
	if (n == 1 || n <= 0)
		return (0);
	else if (n == 2)
		return (1);
	else
		return (prime(n, 2));
}
