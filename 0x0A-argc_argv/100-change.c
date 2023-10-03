#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the minimum number of change for an amount of money
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	int i, change;

	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	change = atoi(argv[1]);
	for (i = 0; change > 0; i++)
	{
		if (change - 25 >= 0)
			change -= 25;
		else if (change - 10 >= 0)
			change -= 10;
		else if (change - 5 >= 0)
			change -= 5;
		else if (change - 2 >= 0)
			change -= 2;
		else if (change - 1 >= 0)
			change -= 1;
	}
	printf("%d\n", i);
	return (0);
}
