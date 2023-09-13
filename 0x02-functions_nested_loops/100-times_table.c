#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the number that will get its time table
 */
void print_times_table(int n)
{
	int a, i, j;

	if (n <= 15 && n >= 0)
	{
		for (i = 0; i <= n; i++)
		{
			_putchar(48);
			for (j = 1; j <= n; j++)
			{
				a = i * j;
				_putchar(',');
				_putchar(' ');
				if (a < 10)
				{
					_putchar(' ');
					_putchar(' ');
				}
				else
				{
					if (a >= 100)
					{
						_putchar((a / 100) + '0');
						_putchar(((a / 10) % 10) + '0');
					}
					else
					{
						_putchar(' ');
						_putchar((a / 10) + '0');
					}
				}
				_putchar((a % 10) + '0');
			}
			_putchar('\n');
		}
	}
}
