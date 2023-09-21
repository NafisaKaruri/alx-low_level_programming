#include "main.h"
#include <ctype.h>

/**
 * string_toupper - changes all lowercase to uppercase letters
 * @s: the string to be edited
 *
 * Return: the string with no lowercase letters converted to upper
 */
char *string_toupper(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (islower(s[i]))
			s[i] = (int)s[i] - 32;
	}
	return (s);
}
