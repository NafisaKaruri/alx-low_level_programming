#include "main.h"

/**
 * _strncat - concatenates two strings
 * @src: the string to be appended to dest
 * @dest: the string that src will be appended to it
 * @n: number of bytes to be added to dest from src
 *
 * Description: similar to _strcat, except:
 *	it will use at most n bytes from src; and
 *	src does not need to be null-terminated if it contains n or more bytes
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*src != '\0' && n > 0)
	{
		*ptr = *src;
		ptr++;
		src++;
		n--;
	}
	*ptr = '\0';
	return (dest);
}
