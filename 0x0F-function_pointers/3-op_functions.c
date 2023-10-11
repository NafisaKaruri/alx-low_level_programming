#include "3-calc.h"

/**
 * op_add - adds two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: the sum of a & b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: the difference between a & b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: the product of a times b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides two integers
 * @a: the first number
 * @b: the second number
 *
 * Return: teh quotient
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - module two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: the remainder
 */
int op_mod(int a, int b)
{
	return (a % b);
}
