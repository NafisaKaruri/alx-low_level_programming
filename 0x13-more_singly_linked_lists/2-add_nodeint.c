#include "lists.h"

/**
 * add_nodeint - adds a new node at the begginning of a list
 * @head: the pointer to the head of the linked list
 * @n: the integer to be added in the node
 *
 * Return: the added node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
