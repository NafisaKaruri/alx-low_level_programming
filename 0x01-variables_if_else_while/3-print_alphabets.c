#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase, then in uppercase
 *
 * Return: 0
 */

int main(void)
{
	char lch = 'a';
	char uch = 'A';

	for (lch = 'a'; lch <= 'z'; lch++)
	{
		putchar(lch);
	}
	for (uch = 'A'; uch <= 'Z'; uch++)
	{
		putchar(uch);
	}
	putchar('\n');
	return (0);
}
