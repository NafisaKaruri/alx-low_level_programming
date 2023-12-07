#include "lists.h"

/**
 * insert_dnodeint_at_index - insersts a new node at a given position
 * @h: pointer to the head of the list in question
 * @idx: the index of the list where the new node should be added.
 *	idx starts at 0
 * @n: the integer to be added to the new node
 *
 * Return: the address of the new node or NULL if it failed
 * if it is not possible to add the new node at index idx,
 * do not add the new node and return NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current = *h, *new_node = malloc(sizeof(dlistint_t));
	unsigned int i;

	if (!new_node)
		return (NULL);
	if (idx == 0)
	{
		new_node->n = n;
		new_node->next = *h;
		new_node->prev = NULL;
		if (*h)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}
	for (i = 0; i < idx - 1; i++)
	{
		if (!current)
		{
			free(new_node);
			return (NULL);
		}
		current = current->next;
	}
	if (!current)
	{
		free(new_node);
		return (NULL);
	}
	new_node->n = n;
	new_node->next = current->next;
	new_node->prev = current;
	current->next = new_node;
	if (new_node->next)
		new_node->next->prev = new_node;
	return (new_node);
}
