#include "main.h"

/**
 * _pow_recursion - returns the value of x ** y
 * @x: the base
 * @y: the power
 *
 * Return: -1 if y < 0, else returns x ** y
 */
int _pow_recursion(int x, int y)
{
	if (x == 0)
		return (0);
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);
	return (x * (_pow_recursion(x, y - 1)));
}
