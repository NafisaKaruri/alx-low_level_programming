#include "lists.h"

/**
 * free_listint_safe - frees a linked list and sets head to NULL
 * @h: pointer to the head of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h, *next;
	size_t i = 0;

	if (!*h)
	{
		return (i);
		exit(98);
	}

	while (current)
	{
		next = current->next;
		free(current);
		i++;

		if (next && current <= next)
		{
			*h = NULL;
			return (i);
		}
		current = next;
	}
	*h = NULL;

	return (i);
}
