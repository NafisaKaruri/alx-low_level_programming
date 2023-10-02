#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: the memory area to be filled
 * @b: the constant byte
 * @n: the number of bytes to be filled in s
 *
 * Description: fills the first n bytes of the memory area
 *		pointed to by s with the constant byte b
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *i;

	for (i = s; i < s + n; i++)
	{
		*i = b;
	}
	return (s);
}
