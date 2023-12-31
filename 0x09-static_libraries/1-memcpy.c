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
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
