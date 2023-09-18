#include "main.h"
#include <string.h>

/**
 * puts_half - prints half of a string
 * @str: the string to be printed
 *
 * Description: prints the second half of the string,
 *	If the number of characters is odd,
 *	the function should print the last n characters of it
 */
void puts_half(char *str)
{
	int i;
	int length = strlen(str);

	if (length % 2 == 0)
	{
		for (i = (length / 2); i < length; i++)
			_putchar(str[i]);
	}
	else
	{
		for (i = ((length - 1) / 2) + 1; i < length; i++)
			_putchar(str[i]);
	}
	_putchar('\n');
}
