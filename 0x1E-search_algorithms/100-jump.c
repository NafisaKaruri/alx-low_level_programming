#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array using jump search algo
 *
 * @array: pinter to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: -1 if value is not present in array or if array is NULL. Else
 *	   return the first index where value is located.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, step;

	/* If the array is NULL or size <= 0 */
	if (!array || size <= 0)
		return (-1);

	/* Let the step be the square root of the array size */
	step = sqrt(size);

	/* Loop with step size till value at the jump index >= value */
	for (i = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);

		/* jump forward by step size */
		i = jump;
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jump);

	/* if jump is greater than the size, set it to last index */
	jump = jump < size - 1 ? jump : size - 1;
	/* Loop from the last jump index to current */
	for (; i <= jump && i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	/*
	* value found
	*if (array[i] == value)
	*{
	*	printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	*	return (i);
	*}
	*/
	/* value not found */
	return (-1);
}
