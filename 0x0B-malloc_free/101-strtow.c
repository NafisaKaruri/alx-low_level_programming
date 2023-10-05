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
	int i, j, x = 0, words = 0, wordlen;

	if (str == NULL || strlen(str) == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		while (str[i] != ' ' && str[i] != '\0')
			i++;
		words++;
	}
	s = malloc(sizeof(char *) * (words + 1));
	if (s == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			wordlen = 0;
			while (str[i] != ' ' && str[i] != '\0')
			{
				wordlen++;
				i++;
			}
			s[x] = malloc(sizeof(char) * (wordlen + 1));
			if (s[x] == NULL)
			{
				for (j = 0; j < x; j++)
					free(s[j]);
				free(s);
				return (NULL);
			}
			for (j = 0; j < wordlen; j++)
			{
				s[x][j] = str[i - wordlen + j];
			}
			s[x][j] = '\0';
			x++;
		}
	}
	s[x] = '\0';
	return (s);
}
