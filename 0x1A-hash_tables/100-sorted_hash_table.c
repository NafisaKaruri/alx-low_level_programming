#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: the size of the hash table, aka arrays
 *
 * Return: pointer to the hash table or NULL if failed
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *sh = malloc(sizeof(shash_table_t));

	if (!sh)
		return (NULL);

	sh->size = size;
	sh->shead = NULL;
	sh->stail = NULL;
	sh->array = malloc(sizeof(shash_node_t *) * size);

	if (!sh->array)
	{
		free(sh);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		sh->array[i] = NULL;

	return (sh);
}

/**
 * update_key - updates the key with new value
 * @node: the node to be updated
 * @value: teh new value
 *
 * Return: 1 if succeeded, 0 otherwise
 */
int update_key(shash_node_t *node, const char *value)
{
	free(node->value);
	node->value = strdup(value);
	if (!node->value)
		return (0);
	return (1);
}

/**
 * ins - inserts a new key
 * @h: the hash table
 * @key: the key to be added
 * @v: the value associated with the key
 * @i: the index
 *
 * Return: 0 if failed, 1 if succeeded
 */
int ins(shash_table_t **h, const char *key, const char *v, unsigned long int i)
{
	shash_node_t *new_node, *temp;

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(v);
	if (!new_node->key || !new_node->value)
	{
		new_node->key ? free(new_node), free(new_node->key) : (void)0;
		new_node->value ? free(new_node), free(new_node->value) : (void)0;
		return (0);
	}
	new_node->next = (*h)->array[i];
	(*h)->array[i] = new_node;
	temp = (*h)->shead;
	while (temp && strcmp(key, temp->key) > 0)
		temp = temp->snext;
	if (!temp)
	{
		new_node->sprev = (*h)->stail;
		new_node->snext = NULL;
		if ((*h)->stail)
			(*h)->stail->snext = new_node;
		else
			(*h)->shead = new_node;
		(*h)->stail = new_node;
	}
	else
	{
		new_node->sprev = temp->sprev;
		new_node->snext = temp;
		if (temp->sprev)
			temp->sprev->snext = new_node;
		else
			(*h)->shead = new_node;
		temp->sprev = new_node;
	}
	return (1);
}

/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: is the hash table to be updated with key/value
 * @key: is the key
 * @value: is the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *node;

	if (!key || !ht || !*key)
		return (0);
	idx = key_index((unsigned char *)key, ht->size);
	node = ht->array[idx];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;
	if (node)
		return (update_key(node, value) == 0);
	else
		return (ins(&ht, key, value, idx));
}
/**
 * shash_table_get - retrieve a value associated with a key
 * @ht: the sorted hash table
 * @key: the key in question
 *
 * Return: the value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int i;
	shash_node_t *node;

	if (!ht || !key || !*key)
		return (NULL);

	i = key_index((unsigned char *)key, ht->size);
	node = ht->array[i];
	if (!node)
		return (NULL);

	if (strcmp(node->key, key) == 0)
		return (node->value);

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints nodes of a sorted hash table
 * @ht: the sorted hash table to be printed
 */
void shash_table_print(const shash_table_t *ht)
{
	unsigned long int i = 0;
	shash_node_t *node = ht->shead;

	if (!ht)
		return;
	printf("{");
	while (node)
	{
		if (i > 0)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		i++;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints sorted nodes in reverse
 * @ht: the sorted hash table to be printed in reverse
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	unsigned long int i = 0;
	shash_node_t *node = ht->stail;

	if (!ht)
		return;
	printf("{");
	while (node)
	{
		if (i > 0)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		i++;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the sorted hash table to be deleted
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node;

	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i])
		{
			node = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = node;
		}
	}
	free(ht->array);
	free(ht);
}
