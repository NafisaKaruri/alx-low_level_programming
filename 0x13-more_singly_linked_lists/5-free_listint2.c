#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and set the head to NULL
 * @head: pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *current = *head, *temp;

	if (!head)
		return;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}
