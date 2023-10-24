#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a linked list
 * @head: a pointer to the head of the linked list
 * @index: the index of the node, starting at 0
 *
 * Return: the nth node, NULL if the node doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *temp = head;
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (!temp)
			return (NULL);
		temp = temp->next;
	}
	return (temp);
}
