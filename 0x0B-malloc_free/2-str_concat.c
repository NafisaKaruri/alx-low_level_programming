#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: NULL on failure, pointer to the alloc space containing s1+s2+\0
 */
char *str_concat(char *s1, char *s2)
{
	char *s;
	unsigned int size, i, j;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	size = strlen(s1) + strlen(s2) + 1;
	s = malloc(sizeof(char) * size);
	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; s1[i] != '\0'; i++)
	{
		s[i] = s1[i];
	}
	for (j = 0; s2[j] != '\0'; j++)
	{
		s[i++] = s2[j];
	}
	s[i] = '\0';
	return (s);
}
