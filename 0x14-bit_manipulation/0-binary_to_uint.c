#include "main.h"

/**
 * power - returns the result of a to the power of b
 * @a: the base
 * @b: the power
 *
 * Return: the result of a to the power of b
 */
unsigned int power(int a, int b)
{
	unsigned int result = 1;

	while (b--)
	{
		result *= a;
	}

	return (result);
}

/**
 * _strlen - returns the string length
 * @s: the string
 *
 * Return: the string lenth
 */
unsigned int _strlen(const char *s)
{
	unsigned int len;

	for (len = 0; s[len] != '\0'; len++)
		;

	return (len);
}

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: is pointing to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if
 *	a- there is one or more chars in the string b that is not 0 or 1
 *	b- b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int uint = 0;
	int i, j = 0;

	if (!b)
		return (0);

	for (i = _strlen(b) - 1; i >= 0; i--)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		uint += (b[i] - '0') * power(2, j);
		j++;
	}

	return (uint);
}
