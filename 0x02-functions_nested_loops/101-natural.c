#include "main.h"

/**
 * main - entry point
 *
 * Description: prints sum of all the multiples of 3 or 5 below 1024
 *
 * Return: always 0
 */
int main(void)
{
	int x = 0;
	int sum = 0;

	while (x < 1024 || (x % 3) == 0 || (x % 5) == 0)
	{
		sum = sum + x;
		x++;
	}
	printf("%d\n", sum);
	return (0);
}
