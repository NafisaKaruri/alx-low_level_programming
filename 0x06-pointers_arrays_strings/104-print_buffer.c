#include "main.h"
#include <stdio.h>

/**
 * isPrintableASCII - checks if n is a printable ASCII character
 * @n: the character to be checked
 *
 * Return: 1 if true, 0 if false
 */
int isPrintableASCII(int n)
{
	return (n >= 32 && n <= 126);
}

/**
 * printHexes - prints b in hex format
 * @b: the character to be printed
 * @begin: begining position
 * @end: ending position
 */
void printHexes(char *b, int begin, int end)
{
	int i = 0;

	while (i < 10)
	{
		if (i < end)
			printf("%02x", *(b + begin + i));
		else
			printf("  ");
		if (i % 2)
			printf(" ");
		i++;
	}
}

/**
 * printASCII - prints b in ASCII format
 * @b: the character to be printed
 * @begin: begining position
 * @end: ending position
 */
void printASCII(char *b, int begin, int end)
{
	int c, i = 0;

	while (i < end)
	{
		c = *(b + i + begin);
		if (!isPrintableASCII(c))
			c = 46;
		printf("%c", c);
		i++;
	}
}

/**
 * print_buffer - prints a buffer
 * @b: the buffer to be printed
 * @size: the bytes of the buffer pointed by b
 *
 * Description: print the content of size bytes of the buffer pointed by b
 *		The output should print 10 bytes per line
 */
void print_buffer(char *b, int size)
{
	int begin, end;

	if (size > 0)
	{
		for (begin = 0; begin < size; begin += 10)
		{
			end = (size - begin < 10) ? size - begin : 10;
			printf("%08x: ", begin);
			printHexes(b, begin, end);
			printASCII(b, begin, end);
			printf("\n");
		}
	}
	else
		printf("\n");
}
