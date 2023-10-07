#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - allocates memory for an array of nmemb elements
 * @nmemb: number of the array elements
 * @size: bytes of each member
 *
 * Return: NULL if nmemb or size is 0, or if malloc fails
 *		otherwise return pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *a;

	if (nmemb == 0 || size == 0)
		return (NULL);
	a = malloc(nmemb * size);
	if (a == NULL)
		return (NULL);
	memset(a, 0, nmemb * size);
	return (a);
}
