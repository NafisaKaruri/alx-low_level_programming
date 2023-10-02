#include <stdio.h>

/**
 * main - prints all arguments it recieves
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: always 0
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
