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
	int i = 1;
	int j = 2;
	int sum = 0;
	int count;

	sum = i + j;
	printf("%d, %d, ", i, j);
	for (count = 0; count < 50; count++)
	{
		sum = i + j;
		if (count == 49)
			printf("%d\n", sum);
		else
			printf("%d, ", sum);
		i = j;
		j = sum;
	}
	return (0);
}
