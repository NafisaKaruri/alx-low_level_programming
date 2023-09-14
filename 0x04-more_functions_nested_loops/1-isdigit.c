#include <ctype.h>

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c: the digit to be checked
 *
 * Return: 1 in case of c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (isdigit(c))
		return (1);
	else
		return (0);
}
