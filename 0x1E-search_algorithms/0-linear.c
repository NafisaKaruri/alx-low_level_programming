#include "search_algos.h"

/**
 * linear_search - searches for a value in an array using linear search
 *
 * @array: pointer to the first element of the aray to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: -1 if value not present or array is NULL. Else
 *	   return the first index where value is located.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	/* If the array is NULL */
	if (!array)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		/* Value found */
		if (array[i] == value)
			return (i);
	}

	/* Value not found */
	return (-1);
}
