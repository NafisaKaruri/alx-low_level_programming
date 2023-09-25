#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: the memory area where we copy the bytes
 * @src: the memory area where we copy from the bytes
 * @n: the number of bytes to be copied
 *
 * Description: copies n bytes from memory area src to memory area dest
 *
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *i;

	for (i = src; i < src + n; i++)
	{
		*dest = *i;
		dest++;
	}
	return (dest);
}
