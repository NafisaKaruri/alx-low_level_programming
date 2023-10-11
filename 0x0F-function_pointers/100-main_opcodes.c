#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 * @argc: arguments counter
 * @argv: arguments vector
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	char *p = (char *)main;
	int a;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	a = atoi(argv[1]);
	if (a < 0)
	{
		printf("Error\n");
		exit(2);
	}
	while (a--)
	{
		printf("%02hhx%s", *p++, a ? " " : "\n");
	}
	return (0);
}
