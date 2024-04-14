#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted list using jump search
 *
 * @list: pointer to the head of the skip list to search in
 * @size: the number of nodes in list
 * @value: the value to search for
 *
 * Return: NULL if value not present or list is NULL. Else
 *         return pointer to the first node where value is located.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, s = 0;
	listint_t *current, *jump;

	/* If list is NULL */
	if (!list || size <= 0)
		return (NULL);

	/* Calculate the steps as sqrt of size */
	step = sqrt(size);
	for (current = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		/* start from the jump point */
		current = jump;
		/* Jump forward by step size */
		for (s += step; jump->index < s; jump = jump->next)
		{
			/* If the end of the list */
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	/* Print the range were the value could be found */
	printf("Value found between indexes [%ld] and [%ld]\n", current->index,
			jump->index);

	/* Linear search the range were the value could be found */
	for (; current->index < jump->index && current->n < value;
			current = current->next)
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);

	/* If value found */
	if (current->n == value)
		return (current);
	/* value not found */
	return (NULL);
}
