#include "hash_tables.h"

/**
 * set - sets space for a new element into the hash table
 * @key: is the key
 * @value: is the value associated with the key
 *
 * Return: pointer to the new node created, NULL if failed
 */
hash_node_t *set(const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (!new_node)
		return (NULL);

	new_node->key = malloc(strlen(key) + 1);
	if (!new_node->key)
		return (NULL);

	new_node->value = malloc(strlen(value) + 1);
	if (!new_node->value)
		return (NULL);

	strcpy(new_node->key, key);
	strcpy(new_node->value, value);
	return (new_node);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: is the hash table you want to add or update the key/value to
 * @key: is the key, it cannot be empty
 * @value: is the value associated with the key. it can be empty,
 * and must be duplicated
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node;

	if (!ht || !key)/*if ht or key are empty, fail*/
		return (0);
	idx = key_index((unsigned char *)key, ht->size);
	node = ht->array[idx];
	if (!node)/*if there is no node there set a new one at end*/
	{
		node = set(key, value);/*call the function that sets*/
		if (!node)
			return (0);
		node->next = NULL;
		ht->array[idx] = node;
		return (1);
	}
	while (node)/*else loop through till the end*/
	{
		if (strcmp(node->key, key) == 0)/*if u find similar key*/
		{
			if (strcmp(node->value, value) == 0)/*with the similar value*/
				return (1);
			free(node->value);/*if not the same value update it*/
			node->value = malloc(strlen(value) + 1);
			if (node->value == NULL)
				return (0);
			strcpy(node->value, value);
			return (1);
		}
		node = node->next;
	}
	if (!node)/*if no similar found till the end*/
	{
		node = set(key, value);/*call the function that sets*/
		if (!node)
			return (0);
		node->next = ht->array[idx];
		ht->array[idx] = node;
		return (1); }
	return (0);
}
