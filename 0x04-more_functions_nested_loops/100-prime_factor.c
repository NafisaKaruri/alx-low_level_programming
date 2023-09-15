#include <stdio.h>

/**
 * largest_pf - prints the largest prime factor
 * @n: the number to find its largest prime factor
 */
void largest_pf(long n)
{
	long i;

	while (n % 2 == 0)
		n = n / 2;
	for (i = 3; i * i <= n; i = i + 2)
	{
		while (n % i == 0)
			n = n / i;
	}
	printf("%lu", n);
}

/**
 * main - entry point
 * Return: always 0
 */
int main(void)
{
	long n = 612852475143;
	largest_pf(n);
	return (0);
}
