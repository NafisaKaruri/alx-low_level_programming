#include "main.h"
#include <math.h>

/**
 * prime - checks if a number is prime
 * @n: the number
 * @val: the number to check if n is divisible by
 *
 * Return: 1 if n is prime, otherwise return 0
 */
int prime(int n, int val)
{
	if (val > sqrt(n))
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
