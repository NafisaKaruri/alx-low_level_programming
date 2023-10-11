#include "dog.h"
#include <stdlib.h>

/**
 * _strcpy - copies s2 to s1
 * @s1: the first string
 * @s2: the second string
 */
void _strcpy(char *s1, char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

/**
 * new_dog - creates a new dog
 * @name: the dog name
 * @age: the dog age
 * @owner: the dog owner
 *
 * Return: the struct dog_t of the new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *nd;
	int s1, s2;

	if (name == NULL || age < 0 || owner == NULL)
		return (NULL);

	nd = malloc(sizeof(dog_t));
	if (nd == NULL)
		return (NULL);

	for (s1 = 0; name[s1] != '\0'; s1++)
		;
	nd->name = malloc(s1 + 1);
	if (nd->name == NULL)
	{
		free(nd);
		return (NULL);
	}

	for (s2 = 0; owner[s2] != '\0'; s2++)
		;
	nd->owner = malloc(s2 + 1);
	if (nd->owner == NULL)
	{
		free(nd->name);
		free(nd);
		return (NULL);
	}

	_strcpy(nd->name, name);
	nd->age = age;
	_strcpy(nd->owner, owner);
	return (nd);
}
