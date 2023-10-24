#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of linked list
 * @head: the head of the linked list
 *
 * Return: the sum of all the data (n) of the linked list
 */
int sum_listint(listint_t *head)
{
	listint_t *current = head;
	int sum = 0;

	while (current)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
