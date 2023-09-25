#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals
 *		of a square matrix of integers
 * @a: the matrix
 * @size: the size of the matrix
 */
void print_diagsums(int *a, int size)
{
	int i, j;
	unsigned int sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
			{
				sum1 = sum1 + *a;
			}
			if (i == size - 1 - j)
			{
				sum2 = sum2 + *a;
			}
			a++;
		}
	}
	printf("%u, %u\n", sum1, sum2);
}