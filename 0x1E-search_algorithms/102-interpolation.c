#include "search_algos.h"

/**
 * interpolation_search - searches a value in sorted array using interpolation
 *
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: -1 if value not found, or if array is NULL, Else
 *	   return the first index where value is located.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t p, pos, low = 0, high = size - 1;

	/* If array is NULL */
	if (!array)
		return (-1);

	while (size)
	{
		/* Calculate the probe position */
		p = (double)(high - low) / (array[high] - array[low]) * (value - array[low]);
		pos = low + p;

		printf("Value checked array[%ld]", pos);

		/* If position out of range */
		if (pos >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
			printf(" = [%d]\n", array[pos]);

		/* If value found in the position */
		if (array[pos] == value)
			return (pos);
		/* move low to next pos */
		if (array[pos] < value)
			low = pos + 1;
		/* move high to previous pos */
		else
			high = pos - 1;

		/* If low and high met, break */
		if (low == high)
			break;
	}

	/* value not found */
	return (-1);
}
