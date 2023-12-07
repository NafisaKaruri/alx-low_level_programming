#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a dlistint_t list
 * @h: the head of the dlistint_t list
 *
 * Return: the number of elements in a dlistint_t list
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t len = 0;

	while (current)
	{
		len++;
		current = current->next;
	}

	return (len);
}
