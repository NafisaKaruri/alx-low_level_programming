#include "search_algos.h"

/**
 * binary_searchs - searches for a value in an array using binary search
 *
 * @array: pointer to the first element of the array to search in
 * @l: the start of the array to search
 * @r: the end of the array to search
 * @value: the value to search for
 *
 * Return: -1 if value not present or array is NULL. Else
 *         return the first index where value is located.
 */
int binary_searchs(int *array, size_t l, size_t r, int value)
{
	size_t i;

	/* If the array is NULL */
	if (!array)
		return (-1);

	for (; l <= r;)
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

/**
 * exponential_search - searches for a value in an array using exponential
 *
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: -1 if value not present or array is NULL. Else
 *         return the first index where value is located.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, right;

	/* If array is NULL */
	if (!array)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	right = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);
	return (binary_searchs(array, i / 2, right, value));
}
