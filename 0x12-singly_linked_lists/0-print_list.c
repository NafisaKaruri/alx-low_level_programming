#include "lists.h"

/**
 * print_list - prints all elements of a list_t list
 * @h: the list to be printed
 *
 * Return: the number of nodes
 */

size_t print_list(const list_t *h)
{
	const list_t *current = h;
	size_t n = 0;

	if (!current)
		return (0);
	while (current)
	{
		if (!current->str)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", current->len, current->str);
		current = current->next;
		n++;
	}

	return (n);
}
