#include <stdio.h>

/**
 * fizz_buzz - print numbers from 1 to 100
 *
 * Description: print Fizz for multiples of 3
 *	print Buzz for multiples of 5
 *	print FizzBuzz for multiples of both 5 and 3
 */
void fizz_buzz(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 != 0)
			printf("Fizz ");
		else if (i % 5 == 0 && i % 3 != 0)
			printf("Buzz ");
		else if (i % 3 == 0 || i % 3 == 0)
			printf("FizzBuzz ");
		else
			printf("%d ", i);
	}
}

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	fizz_buzz();
	return (0);
}
