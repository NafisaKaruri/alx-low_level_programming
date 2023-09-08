#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Assign a random number to n, print the last digit
 *
 * Return: 0
 */

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	l = n % 10;
	if (l > 5)
	{
		printf("Last digit of %i is %d and is greater than 5\n", n, l);
	}
	else if (l == 0)
	{
		printf("Last digit of %i is %d and is 0\n", n);
	}
	else
	{
		printf("Last digit of %i is %d and is", n);
	}
	return (0);
}
