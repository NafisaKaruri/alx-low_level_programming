#include "lists.h"

/**
 * listint_len - return the number of elements in a linked list
 * @h: the lsit
 *
 * Return: the number of elements in a linked list
 */
size_t listint_len(const listint_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}

	return (i);
}
