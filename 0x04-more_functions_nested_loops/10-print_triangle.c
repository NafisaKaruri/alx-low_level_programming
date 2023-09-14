#include "main.h"

/**
 * print_triangle - prints a triangle
 * @size: the size of the triangle
 */
void print_triangle(int size)
{
	int i, j;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (j < size - 1 - i)
					_putchar(' ');
				else
					_putchar(35);
			}
		_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
