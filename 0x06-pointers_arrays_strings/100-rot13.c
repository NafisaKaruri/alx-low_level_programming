#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @s: the string to be encoded
 *
 * Return: the encoded string
 */
char *rot13(char *s)
{
	char a1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char a2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; a1[j] != '\0'; j++)
		{
			if (s[i] == a1[j])
			{
				s[i] = a2[j];
				break;
			}
		}
	}
	return (s);
}
