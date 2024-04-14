#include "search_algos.h"

/**
 * recursive_binary - searches for a value in an array using binary search
 *
 * @array: pointer to the first element of the aray to search in
 * @l: the start of the array to search
 * @r: the end of the array to search
 * @value: the value to search for
 *
 * Return: -1 if value not present or array is NULL. Else
 *	   return the first index where value is located.
 */
int recursive_binary(int *array, size_t l, size_t r, int value)
{
	size_t i;

	if (l > r)
		return (-1);
	/* Print the part being searched */
	printf("Searching in array: ");
	for (i = l; i < r; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	/* Find the middle of the array */
	i = l + (r - l) / 2;
	/* Value found in middle */
	if (array[i] == value && (i == l || array[i - 1] != value))
		return (i);
	/* If value is less than middle, move the right boundary to middle */
	if (array[i] >= value)
		return (recursive_binary(array, l, i, value));

	return (recursive_binary(array, i + 1, r, value));
}

/**
 * advanced_binary - call recursive_binary
 *
 * @array: pointer to the first element of the aray to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: -1 if value not present or array is NULL. Else
 *         return the first index where value is located.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size <= 0)
		return (-1);
	return (recursive_binary(array, 0,  size - 1, value));
}
