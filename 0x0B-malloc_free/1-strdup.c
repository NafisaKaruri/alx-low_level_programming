#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *		containing a copy of str
 * @str: the string
 *
 * Return: NULL if str = NULL,
 *		otherwise pointer to a new string,
 *		NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *s;
	unsigned int i;

	if (str == NULL)
	{
		return (NULL);
	}
	s = malloc(sizeof(char) * strlen(str));
	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < strlen(str); i++)
	{
		s[i] = str[i];
	}
	return (s);
}
