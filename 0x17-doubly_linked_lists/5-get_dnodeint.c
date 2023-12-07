#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: the head of the dlistint_t linked list
 * @index: the index of the node, starting from 0
 *
 * Return: the nth node of dlistint_t list, NULL if it doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp = head;
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (!temp)
			return (NULL);
		temp = temp->next;
	}
	return (temp);
}
