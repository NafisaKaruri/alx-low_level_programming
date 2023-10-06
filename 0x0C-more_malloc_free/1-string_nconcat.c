#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenate two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the number of bytes of s2 to be concatenated
 *
 * Description: Create a new string containing s1,
 *		followed by the first n bytes of s2,
 *		and null terminated.
 *		If n is greater or equal to the length of s2
 *		then use the entire string s2.
 *		If NULL is passed, treat as an empty string.
 *
 * Return: NULL if function fails, otherwise pointer to new string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (n >= strlen(s2))
		n = strlen(s2);
	s = malloc(strlen(s1) + n + 1);
	for (i = 0; i < strlen(s1); i++)
		s[i] = s1[i];
	for (j = 0; j < n; j++)
	{
		s[i] = s2[j];
		i++;
	}
	s[i] = '\0';
	return (s);
}
