#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to get its last digit
 *
 * Return: the last digit of n
 */

int print_last_digit(int n)
{
	int x;

	if (n < 0)
		x = -((unsigned int)n) % 10;
	else
		x = n % 10;
	_putchar(x + '0');
	return (x);
}
