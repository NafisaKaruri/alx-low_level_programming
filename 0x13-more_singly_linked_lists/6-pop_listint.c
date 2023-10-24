#include "lists.h"

/**
 * pop_listint - deletes the head node of linked list
 * @head: pointer to the head of the linked list
 *
 * Return: the head node's data (n)
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (!*head)
		return (0);
	temp = *head;
	n = temp->n;
	*head = temp->next;
	free(temp);
	return (n);
}
