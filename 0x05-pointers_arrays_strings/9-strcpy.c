#include "main.h"
#include <string.h>

/**
 * _strcpy - copies the string pointed to by src,
 *		to buffer pointed to by dest
 * @dest: destination of the copied string
 * @src: source from which string is copied
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *x;

	x = strcpy(dest, src);
	return (x);
}
