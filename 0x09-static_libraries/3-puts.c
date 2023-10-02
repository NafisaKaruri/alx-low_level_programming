#include "main.h"
#include <string.h>

/**
 * _puts - prints a string followed by a new line, to stdout
 * @str: the string to be printed
 */
void _puts(char *str)
{
	size_t i = 0;

	for (i = 0; i < strlen(str); i++)
		_putchar(str[i]);
	_putchar('\n');
}
