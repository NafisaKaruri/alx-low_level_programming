#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: the size of the array
 *
 * Return: pointer to the newly created hash table,
 * or NULL if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *h = malloc(sizeof(hash_table_t));

	if (!h)
		return (NULL);

	h->size = size;
	h->array = malloc(sizeof(hash_node_t *) * size);
	if (!h->array)
		return (NULL);

	for (i = 0; i < size; i++)
		h->array[i] = NULL;

	return (h);
}
