#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints all possible different combinations of three digits
 *
 * Return: 0
*/

int main(void)
{
	int d1, d2, d3;

	for (d1 = 0; d1 <= 7; d1++)
	{
		for (d2 = d1 + 1; d2 <= 8; d2++)
		{
			for (d3 = d2 + 1; d3 <= 9; d3++)
			{
				putchar(d1 + '0');
				putchar(d2 + '0');
				putchar(d3 + '0');
				if (d1 + d2 + d3 != 24)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
