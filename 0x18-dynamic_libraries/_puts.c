#include <unistd.h>
#include "main.h"

/**
 * _puts - writes s
 * @s: The string to print
 *
 * Return: on success 1
 *              on error -1
 */

void _puts(char *s)
{
        int len = _strlen(s);

	write(1, s, len);
	write(1, "\n", 1);
}
