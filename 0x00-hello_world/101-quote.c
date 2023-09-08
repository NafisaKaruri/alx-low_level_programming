#include <unistd.h>
/**
 * main - Entry point
 *
 * Description: Print text using write function
 *
 * Return: 1
 */
int main(void)
{
	char quot[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(1, quot, 59);
	return (1);
}
