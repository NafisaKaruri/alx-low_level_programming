#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: is the hash table to be printed
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, j = 0;
	hash_node_t *node;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			node = ht->array[i];
			while (node)
			{
				if (j > 0)
					printf(", ");
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				j++;
			}
		}
	}
	printf("}\n");
}
