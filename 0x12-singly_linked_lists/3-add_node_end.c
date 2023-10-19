#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: the head of the list_t list
 * @str: the string to be added to the new node
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *current;
	list_t *new_node = malloc(sizeof(list_t));
	unsigned int len;

	if (!new_node)
		return (NULL);

	if (!str)
	{
		new_node->str = NULL;
		new_node->len = 0;
	}
	else
	{
		for (len = 0; str[len]; len++)
			;
		new_node->str = strdup(str);
		new_node->len = len;
	}
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
