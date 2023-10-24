#include "lists.h"

/**
 * reverse_listint - reverse a linked list
 * @head: pointer to the head of the linked list
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current = *head, *next = NULL;

	if (!*head)
		return (NULL);

	*head = NULL;
	while (current)
	{
		next = current->next;
		current->next = *head;
		*head = current;
		current = next;
	}
	return (*head);
}
