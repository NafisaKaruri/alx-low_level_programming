#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/**
 * main - Entry point
 *
 * Description: Assign a random number to n, and print whether its -ve or +ve
 *
 * Return: 0
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
	{
		printf("%i is postive\n", n);
	}
	else if (n == 0)
	{
		printf("%i is zero", n);
	}
	else
	{
		printf("%i is negative", n);
	return (0);
}
