#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - adds positive numbers
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 1 if one of passed numbers is not digit, 0 otherwise
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int sum = 0, i = 1, j;

	if (argc == 1)
	{
		printf("%d\n", sum);
		return (0);
	}
	else
	{
		while (i < argc)
		{
			for (j = 0; argv[i][j] != '\0'; j++)
			{
				if (!isdigit(argv[i][j]))
				{
					printf("Error\n");
					return (1);
				}
			}
			sum = sum + atoi(argv[i]);
			i++;
		}
		printf("%d\n", sum);
		return (0);
	}
}
