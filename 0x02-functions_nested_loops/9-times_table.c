#include "main.h"

/**
 * times_table - prints the 9 times table
 */

void times_table(void)
{
	int a = 0;
	int b, i;

	while (a <= 9)
	{
		b = 1;

		_putchar(48);
		while (b <= 9)
		{
			i = a * b;

			_putchar(',');
			_putchar(' ');
			if (i <= 9)
				_putchar(' ');
			else
				_putchar((i / 10) + '0');
			_putchar((i % 10) + '0');
			b++;
		}
		_putchar('\n');
		a++;
	}
}
