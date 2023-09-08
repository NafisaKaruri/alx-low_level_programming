#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: print all single-digit nubers seperated by ,
 *
 * Return: 0
 */

int main(void)
{
	int n = 0;

	for (n = 0; n <= 9; n++)
	{
		putchar(n + '0');
		putchar(',');
		if (n < 9)
			putchar(' ');
	}
	putchar('\n');
	return (0);
}
