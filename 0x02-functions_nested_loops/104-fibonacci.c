#include "main.h"

/**
 * nlength - returns the length of string
 * @n: operand number
 *
 * Return: number of digits
 */
int nlength(int n)
{
	int length = 0;

	if (!n)
		return (1);
	while (n)
	{
		n = n / 10;
		length += 1;
	}
	return (length);
}

/**
 * main - entry point
 *
 * Descriptionn: prints the first 98 fibonacci no.s
 *
 * Return: always 0
 */
int main(void)
{
	int count, z;
	unsigned long i = 1, j = 2, sum, max = 100000000, io = 0, jo = 0, sumo = 0;

	for (count = 1; count <= 98; count++)
	{
		if (io > 0)
			printf("%lu", io);
		z = nlength(max) - 1 - nlength(i);

		while (io > 0 && z > 0)
		{
			printf("%d", 0);
			z--;
		}
		printf("%lu", i);

		sum = (i + j) % max;
		sumo = io + jo + (i + j) / max;
		i = j;
		io = jo;
		j = sum;
		jo = sumo;

		if (count != 98)
			printf(", ");
		else
			printf("\n");
	}
	return (0);
}
