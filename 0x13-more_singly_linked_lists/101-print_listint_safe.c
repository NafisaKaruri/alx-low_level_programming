#include "lists.h"

/**
 * print_listint_safe - prints a linked list
 * @head: the head of the linked list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t i = 0;

	if (!head)
		exit(98);

	while (current)
	{
		printf("[%p] %i\n", (void *)current, current->n);
		i++;

		if (current <= current->next)
		{
			printf("-> [%p] %i\n", (void *)current->next, current->next->n);
			exit(98);
		}
		current = current->next;
	}

	return (i);
}
