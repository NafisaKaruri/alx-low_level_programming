#include <stdio.h>

/**
 * main - print the number of arguments passed to it
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: always 0
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
