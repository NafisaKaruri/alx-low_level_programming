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
	int i;
	unsigned int sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 = sum1 + *(a + i * size + i);
	}
	for (i = 0; i < size; i++)
	{
		sum2 = sum2 + *(a + i * size + (size - 1 - i));
	}
	printf("%u, %u\n", sum1, sum2);
}
