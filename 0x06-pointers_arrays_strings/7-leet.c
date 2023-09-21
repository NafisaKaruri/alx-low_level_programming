#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: the string to be encoded
 *
 * Return: the encoded string
 */
char *leet(char *s)
{
	char letters[] = {'a', 'e', 'o', 't', 'l'};
	int replacers[] = {'4', '3', '0', '7', '1'};
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
			if (s[i] == letters[j] || s[i] == letters[j] - 32)
			{
				s[i] = replacers[j];
			}
	}
	return (s);
}
