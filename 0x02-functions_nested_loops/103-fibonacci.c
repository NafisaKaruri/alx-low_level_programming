#include "main.c"

/**
 * main - entry point
 *
 * Description: prints the sum of the even fibonacci no.s
 *
 * Return: always 0
 */
int main(void)
{
	unsigned long i = 0;
	unsigned long j = 1;
	unsigned long sum;
	float esum;

	while (1)
	{
		sum = i + j;

		if (sum > 4000000)
			break;
		if (sum % 2 == 0)
			esum = esum + sum;
		i = j;
		j = sum;
	}
	printf("%.0f\n", esum);
	return (0);
}
