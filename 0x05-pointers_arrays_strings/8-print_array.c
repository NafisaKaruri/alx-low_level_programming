#include "main.h"
#include <stdio.h>
/**
 * print_array - prints n elements of an array of integers
 * @a: the array of integers to be printed
 * @n: number of elements to be printed
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		while (i < n - 1)
		{
			printf("%d, ", a[i]);
			i++;
		}
		printf("%d\n", a[n - 1]);
	}
}
