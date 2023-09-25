#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to be scanned
 * @accept: string containing the characters to match
 *
 * Description: calculates the length of the initial segment of s
 *		which consists entirely of bytes in accept
 *
 * Return: number of bytes in the initial segment of s which
 *		consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;

	for ( i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != s[i]; j++)
		{
			if (accept[j] == '\0')
			{
				return(i);
			}
		}		
	}
	return (i);
}
