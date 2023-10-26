#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number
 */
void print_binary(unsigned long int n)
{
	int end;

	if (n > 1)
		print_binary(n >> 1);
	end = n & 1;
	_putchar(end + '0');
}
