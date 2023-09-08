#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints all single digit numbers of base 10 from 0 using putchar
 *
 * Return: 0
 */

int main(void)
{
	int n = 0;

	for (n = 0; n <= 9; n++)
	{
		putchar('0' + n % 10);
	}
	putchar('\n');
	return (0);
}
