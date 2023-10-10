#include "dog.h"
#include <stdlib.h>

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

	if (!name || age < 0 || !owner)
		return (NULL);

	nd = malloc(sizeof(dog_t));
	if (nd == NULL)
		return (NULL);

	for (s1 = 0; name[s1] != '\0'; s1++)
		;
	nd->name = malloc(s1);
	if ((*nd).name == NULL)
	{
		free(nd);
		return (NULL);
	}

	for (s2 = 0; owner[s2] != '\0'; s2++)
		;
	nd->owner = malloc(s2);
	if ((*nd).owner == NULL)
	{
		free(nd);
		free(nd->name);
		return (NULL);
	}

	nd->name = name;
	nd->age = age;
	nd->owner = owner;
	return (nd);
}
