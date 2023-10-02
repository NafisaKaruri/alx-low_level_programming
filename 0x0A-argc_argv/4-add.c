#include <stdio.h>
#include <stdlib.h>

/**
 * main - adds positive numbers
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 1 if one of passed numbers is not digit, 0 otherwise
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int sum = 0, i = 1;

	if (argc == 1)
	{
		printf("%d\n", sum);
		return (0);
	}
	else
	{
		while (i < argc)
		{
			if (atoi(argv[i]) == 0 && *argv[i] != '0')
			{
				printf("Error\n");
				return (1);
			}
			else
			{
				sum = sum + atoi(argv[i]);
			}
			i++;
		}
		printf("%d\n", sum);
		return (0);
	}
}
