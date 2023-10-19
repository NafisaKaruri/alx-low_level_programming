#include "lists.h"

/**
 * list_len - return the number of elements in a linked list_t list
 * @h: the list header
 *
 * Return: the number of elements in a linked list_t list
 */
size_t list_len(const list_t *h)
{
	const list_t *current = h;
	size_t n = 0;

	while (current)
	{
		n++;
		current = current->next;
	}

	return (n);
}
