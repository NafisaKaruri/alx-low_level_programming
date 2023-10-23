#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a list
 * @head: the head of the list
 * @n: the integer to be added into the new node
 *
 * Return: the new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *current, *new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}

	return (new_node);
}
