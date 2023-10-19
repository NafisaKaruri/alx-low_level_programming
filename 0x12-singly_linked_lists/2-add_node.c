#include "lists.h"

/**
 * add_node - adds a new node at the beggining of a list_t list
 * @head: the head of the list_t list
 * @str: the string to be added to the new node
 *
 * Return: the address of the new element, or NULL if failed
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));
	unsigned int len;

	if (!new_node)
		return (NULL);
	if (!str)
		return (NULL);

	for (len = 0; str[len]; len++)
		;
	new_node->str = strdup(str);
	new_node->len = len;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
