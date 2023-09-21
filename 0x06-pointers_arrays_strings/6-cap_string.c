#include "main.h"
#include <ctype.h>
#include <string.h>
/**
 * cap_string - capitalizes all words of a string
 * @s: the string to be edited
 *
 * Return: the edited string
 */
char *cap_string(char *s)
{
	int i;
	char separators[] = " \t\n,;.!?'\"(){}";

	for (i = 0; s[i] != '\0'; i++)
	{
		if (i == 0 || strchr(separators, s[i]) != NULL)
		{
			if (isalpha(s[i + 1]) && islower(s[i + 1]))
				s[i + 1] = (int)s[i + 1] - 32;
		}
	}
	return (s);
}
