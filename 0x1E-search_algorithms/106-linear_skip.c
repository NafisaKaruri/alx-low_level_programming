#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 *
 * @list: pointer to the head of the skip list to search in
 * @value: the value to search for
 *
 * Return: NULL if value not present in list or list is NULL. Else
 *	   return pointer to the first node where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *jump;

	/* If the list is NULL */
	if (!list)
		return (NULL);

	/* Start from head */
	current = jump = list;
	while (jump->next && jump->n < value)
	{
		/* Move current to jump */
		current = jump;

		/* If jump has an express lane */
		if (jump->express)
		{
			/* Move the jump to the next node in express lane */
			jump = jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
					jump->index, jump->n);
		}
		else
			/* Move the jump to next node in list */
			while (jump->next)
				jump = jump->next;
	}
	/* Print the range were value could be found */
	printf("Value found between indexes [%ld] and [%ld]\n", current->index,
			jump->index);

	for (; current->index < jump->index && current->n < value;
			current = current->next)
		printf("Value checked at index [%ld] = [%d]\n", current->index,
				current->n);
	printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	/* If value found */
	if (current->n == value)
		return (current);
	/* value not found */
	return (NULL);
}
