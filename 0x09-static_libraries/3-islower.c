#include "main.h"
#include <ctype.h>

/**
 * _islower - cheks for lowercase character
 * @c: character to be checked
 *
 * Return: on success 1, otherwise 0
 */

int _islower(int c)
{
	if (islower(c))
		return (1);
	else
		return (0);
}
