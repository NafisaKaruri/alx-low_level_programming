#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * print - print numbers
 * @n: the integer to be printed
 */
void print(unsigned long int n)
{
	unsigned long int x;

	x = n;
	if (x / 10 != 0)
	{
		print(x / 10);
	}
	_putchar((x % 10) + '0');
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: the string as an integer
 */
unsigned long int _atoi(char *s)
{
	unsigned long int result = 0;
	int sign = 1;

	do {
		if (*s == '-')
			sign = sign * -1;
		else if (*s >= '0' && *s <= '9')
			result = (result * 10) + (*s - '0');
		else if (result > 0)
			break;
	} while (*s++);
	return (sign * result);
}

/**
 * exiting - prints ERROR, and exit with a status of 98
 */
void exiting(void)
{
	char *e = "ERROR";
	unsigned long int i;

	for (i = 0; e[i] != '\0'; i++)
		_putchar(e[i]);
	_putchar('\n');
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument counter
 * @argv: argument vector
 *
 * Description: print the result of num1 * num2 followed by new line
 *		if the number of argument is in correct print ERROR,
 *		and exit with a status of 98
 *		num1 and num2 should only be composed of digits. if
 *		not print ERROR, and exit with status of 98
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	unsigned long int i, j;

	if (argc != 3)
		exiting();
	for (i = 1; argv[i]; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				exiting();
		}
	}
	print(_atoi(argv[1]) * _atoi(argv[2]));
	_putchar('\n');
	return (0);
}
