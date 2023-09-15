#include "main.h"

/**
 * print_number - prints at integer
 * @n: the integer to be printed
 */
void print_number(int n)
{
	unsigned int x = n;
	if (n < 0)
	{
		n = -n;
		_putchar('-');
	}
	if (x / 10)
	{
		print_number(x / 10);
	}
	_putchar((x % 10) + '0');
}
