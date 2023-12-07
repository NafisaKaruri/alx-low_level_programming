#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: the header of the dlistint_t list
 *
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t i = 0;

	if (!current)
		return (0);
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
		i++;
	}

	return (i);
}
