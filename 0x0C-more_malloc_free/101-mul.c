#include "main.h"
#include <stdlib.h>

/**
 * _strlen - counts the number of characters in a string
 * @s: the string
 *
 * Return: the string length
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _isdigit - checks if the string is digit or not
 * @s: the string
 *
 * Return: 1 if the string is digit, else 0
 */
int _isdigit(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * exiting - prints ERROR, and exit with a status of 98
 */
void exiting(void)
{
	char *e = "Error";
	int i;

	for (i = 0; e[i]; i++)
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
	int len1, len2, len, i, j = 0, carry, d1, d2, *result;
	char *num1, *num2;

	num1 = argv[1], num2 = argv[2];
	if (argc != 3 || !(_isdigit(num1)) || !(_isdigit(num2)))
		exiting();
	len1 = _strlen(num1), len2 = _strlen(num2), len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (result == NULL)
		return (1);
	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		d1 = num1[len1] - 48;
		carry = 0;
		for (len2 = _strlen(num2) - 1; len2 >= 0; len2--)
		{
			d2 = num2[len2] - 48;
			carry += result[len1 + len2 + 1] + (d1 * d2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			j = 1;
		if (j)
			_putchar(result[i] + 48);
	}
	if (!j)
		_putchar('0');
	_putchar('\n');
	free(result);

	return (0);
}
