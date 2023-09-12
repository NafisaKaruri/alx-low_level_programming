#include <ctype.h>

/**
 * 4-isalpha.c - checks for alphabetic character
 * @c: The character to be checked
 *
 * Return: on success 1, otherwise 0
 */

int _isalpha(int c)
{
	if (isalpha(c))
		return (1);
	else
		return (0);
}
