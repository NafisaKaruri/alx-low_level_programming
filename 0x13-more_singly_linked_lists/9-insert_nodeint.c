#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node node at a given position
 * @head: pointer to the head of a linked list
 * @idx: the index of the list where the new node should be added
 * @n: the integer to be added in the new node
 *
 * Return: the address of the new node or NULL if it failed
 * if it is not possible to add the new node at index idx,
 * do not add the new node and return NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current = *head, *new_node = malloc(sizeof(listint_t));
	unsigned int i;

	if (!new_node)
		return (NULL);

	for (i = 0; i < idx - 1; i++)
	{
		if (!current)
			return (NULL);
		current = current->next;
	}

	new_node->n = n;
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
