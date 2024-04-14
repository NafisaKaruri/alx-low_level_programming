#include "search_algos.h"

/**
 * binary_search - searches for a value in an array using binary search
 *
 * @array: pointer to the first element of the aray to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: -1 if value not present or array is NULL. Else
 *	   return the first index where value is located.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, l, r;

	/* If the array is NULL */
	if (!array)
		return (-1);

	for (l = 0, r = size - 1; l <= r; i++)
	{
		/* Print the part being searched */
		printf("Searching in array: ");
		for (i = l; i < r; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		/* Find the middle of the array */
		i = l + (r - l) / 2;
		/* Value found in middle */
		if (array[i] == value)
			return (i);
		/* If value is less than middle, move the right boundary to middle */
		if (array[i] > value)
			r = i - 1;

		/* Else, move the left boundary to middle */
		else
			l = i + 1;
	}

	/* Value not found */
	return (-1);
}
