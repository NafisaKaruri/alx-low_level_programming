#include <stdio.h>

/**
 * main - prints the program name
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 0
 */
int __attribute__((unused)) main(int argc, char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
