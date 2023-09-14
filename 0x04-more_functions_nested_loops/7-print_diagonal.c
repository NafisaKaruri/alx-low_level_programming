#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: the number of times the character \ should be printed
 */
void print_diagonal(int n)
{
	int i;

	for (i = 0; i < n; i++)
		_putchar(92);
	_putchar('\n');
}
