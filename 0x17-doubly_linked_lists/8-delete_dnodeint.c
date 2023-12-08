#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a list
 * @h: pointer to the head of the list
 * @index: the index of the node in question
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head, *temp;
	unsigned int i;

	if (!current)
		return (-1);
	if (index == 0)
	{
		*head = current->next;
		if (current->next)
			current->next->prev = NULL;
		free(current);
		return (1);
	}
	for (i = 0; i < index - 1; i++)
	{
		if (!current->next)
			return (-1);
		current = current->next;
	}

	temp = current->next;
	if (!temp)
		return (-1);
	current->next = temp->next;
	if (temp->next)
		temp->next->prev = current;
	free(temp);
	return (1);
}
