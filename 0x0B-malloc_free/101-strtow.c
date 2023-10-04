#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * strtow - splits a string into words
 * @str: the string
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **s;
	int i, j, x = 0, y;

	if (str == NULL || strlen(str) == 0)
		return (NULL);
	s = malloc(sizeof(char *) * (strlen(str) + 1));
	if (s == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			y = 0;
			while (str[i] != ' ' && str[i] != '\0')
			{
				y++;
				i++;
			}
			s[x] = malloc(sizeof(char) * (y + 1));
			if (s[x] == NULL)
			{
				for (j = 0; j < x; j++)
					free(s[j]);
				free(s);
				return (NULL);
			}
			for (j = 0; j < y; j++)
			{
				s[x][j] = str[i - y + j];
			}
			s[x][j] = '\0';
			x++;
		}
	}
	s[x] = '\0';
	return (s);
}
