#include "lists.h"

/**
 * print_listint_safe - prints a linked list
 * @head: the head of the linked list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head, *printed[100] = {NULL};
	size_t i = 0, j;

	if (!head)
		exit(98);

	while (current)
	{
		for (j = 0; j < i; j++)
		{
			if (printed[j] == current)
			{
				printf("-> [%p] %i\n", (void *)current->next, current->next->n);
				return (i);
			}
		}
		printed[i] = current;
		printf("[%p] %i\n", (void *)current, current->n);
		i++;

		current = current->next;
	}

	return (i);
}
