#include "main.h"

/**
 * main - entry point
 *
 * Description: prints first 50 Fibonacci numbers, starting with 1 and 2
 *
 * Return: always 0
 */

int main(void)
{
	unsigned long i = 1;
	unsigned long j = 2;
	unsigned long sum = 0;
	int count;

	sum = i + j;
	printf("%lu, %lu, ", i, j);
	for (count = 22; count < 50; count++)
	{
		sum = i + j;
		if (count == 49)
			printf("%lu\n", sum);
		else
			printf("%lu, ", sum);
		i = j;
		j = sum;
	}
	return (0);
}
