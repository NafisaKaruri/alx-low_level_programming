#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 1 if no arguments recieved, 0 otherwise
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int product = 1, i = 1;

	if (argc <= 1)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		while (i < argc)
		{
			product = product * atoi(argv[i]);
			i++;
		}
		printf("%d\n", product);
		return (0);
	}
}
