#include "main.h"
#include <string.h>

/**
 * _strstr - locates a substring
 * @haystack: the string
 * @needle: the substring
 *
 * Description: finds the first occurrence of the substring needle in the string haystack
 *
 * Return: pointer to the beginning of the located substring
 *		or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	size_t n = strlen(needle);

	while(*haystack)
	{
		if (!memcmp(haystack, needle, n))
		{
			return (haystack);
		}
		haystack++;
	}
	return NULL;
}
