#include "main.h"
#include <string.h>

/**
 * pal - checks if a string is palindrome
 * @s: the string
 * @i: counter from the beginning of the string
 * @j: counter from the ending of the string
 *
 * Return: 1 if string is a palindrome, 0 if not
 */
int pal(char *s, int i, int j)
{
	if (s[i] !=  s[j])
		return (0);
	if (i < j + 1)
		return (pal(s, i + 1, j - 1));
	return (1);
}

/**
 * is_palindrome - checks if a string is palindrome
 * @s: the string
 *
 * Return: 1 if string is a palindrome, 0 if not
 */
int is_palindrome(char *s)
{
	if (strlen(s) == 0 || strlen(s) == 1)
		return (1);
	return (pal(s, 0, strlen(s) - 1));
}
