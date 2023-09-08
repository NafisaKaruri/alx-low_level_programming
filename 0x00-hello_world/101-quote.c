#include <unistd.h>
/**
 * main - Entry point
 *
 * Description: Print text followed by new line
 *
 * Return: 1
 */
int main(void)
{
	char quote[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(1, quote, 59);
	return (1);
}
