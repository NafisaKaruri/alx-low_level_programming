#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * argstostr - concatenates all the arguments of your program
 * @ac: argument counter
 * @av: argument vector
 *
 * Return: NULL if ac = 0 or av == NULL,
 *		otherwise pointer to a new string,
 *		NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *s;
	int i, j, size = 0, x = 0;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		size = size + strlen(av[i]);
	}
	s = malloc(sizeof(char) * (size + ac + 1));
	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			s[x] = av[i][j];
			x++;
		}
		s[x] = '\n';
		x++;
	}
	s[x] = '\0';
	return (s);
}
