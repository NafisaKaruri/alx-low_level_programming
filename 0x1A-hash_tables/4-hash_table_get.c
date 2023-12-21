#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table you want to look into
 * @key: the key you are looking for
 *
 * Return: teh value associated with the element, or NULL if key not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *node;

	if (!ht || !key)
		return (NULL);

	idx = key_index((unsigned char *)key, ht->size);
	node = ht->array[idx];
	if (!node)/*if the node not found*/
		return (NULL);

	if (strcmp(node->key, key) == 0)/*is the node key the same as our key*/
		return (node->value);

	while (node)/*the first wasn't the node, so we loop in that idx*/
	{
		if (strcmp(node->key, key) == 0)/*found*/
			return (node->value);
		node = node->next;
	}

	return (NULL);/*doesn't exist*/
}
