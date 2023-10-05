#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * words - count the number of words
 * @s: the string
 *
 * Return: the number of words
 */
int words(char *s)
{
	int i, x = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == ' ')
		{
			if (s[i + 1] != ' ' && s[i + 1] != '\0')
				x++;
		}
		else if (i == 0)
			x++;
	}
	x++;
	return (x);
}

/**
 * strtow - splits a string into words
 * @str: the string
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **s;
	int i, j, k, l, n = 0, w = 0;

	if (str == NULL || strlen(str) == 0)
		return (NULL);
	n = words(str);
	if (n == 1)
		return (NULL);
	s = (char **)malloc(sizeof(char *) * n);
	if (s == NULL)
		return (NULL);
	s[n - 1] = NULL;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			for (j = 1; str[i + j] != ' ' && str[i + j]; j++)
				;
			j++;
			s[w] = (char *)malloc(sizeof(char) * j);
			j--;
			if (s[w] == NULL)
			{
				for (k = 0; k < w; k++)
					free(s[k]);
				free(s[n - 1]);
				free(s);
				return (NULL);
			}
			for (l = 0; l < j; l++)
				s[w][l] = str[i + l];
			s[w][l] = '\0';
			w++;
			i += j;
		}
	}
	return (s);
}
