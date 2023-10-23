#include "lists.h"

/**
 * free_listint - free a listint_t list
 * @head: the head of the list
 */
void free_listint(listint_t *head)
{
	listint_t *current = head;
	
	while (head)
	{
		head = head->next;
		free(current);
		current = head;
	}
}
