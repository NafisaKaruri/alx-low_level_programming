#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: the minimum integer in the array
 * @max: the maximum integer in the array
 *
 * Return: NULL if min > max, or malloc fails
 */
int *array_range(int min, int max)
{
	int *a;
	int i, j = 0, size = (max - min + 1);

	if (min > max)
		return (NULL);
	a = malloc(sizeof(int) * size);
	if (a == NULL)
		return (NULL);
	for (i = min; i <= max; i++)
	{
		a[j] = i;
		j++;
	}
	return (a);
}
