#include "main.h"

/**
 * _strncpy - copies the string pointed to by src, to dest
 * @dest: destination of the copied string
 * @src: source from which string is copied
 * @n: the number of bytes to be copied from src
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *ptr = dest;
	int i = 0;

	while (*src != '\0' && i < n)
	{
		*ptr = *src;
		ptr++;
		src++;
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
