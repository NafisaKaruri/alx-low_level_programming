#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and set the head to NULL
 * @head: pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *current = *head;

	while (current)
	{
		*head = current->next;
		free(current);
		current = *head;
	}

	*head = NULL;
	head = NULL;
}
