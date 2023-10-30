#include "main.h"
#include <sys/stat.h>

/**
 * read_err - prints the error text and exits
 * @argv: argument vector
 */
void read_err(char **argv)
{
	dprintf(2, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
}

/**
 * write_err - prints the error text and exits
 * @argv: argument vector
 */
void write_err(char **argv)
{
	dprintf(2, "Error: Can't write to %s\n", argv[2]);
	exit(99);
}

/**
 * main - copies the content of a file to another file
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	int fd, fd1, r, wcount, c;
	char buffer[1024];
	mode_t oldmask;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		read_err(argv);

	oldmask = umask(0);
	fd1 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	umask(oldmask);
	if (fd1 == -1)
		write_err(argv);

	while ((r = read(fd, buffer, 1024)) > 0)
	{
		wcount = write(fd1, buffer, r);
		if (wcount != r)
			write_err(argv);
	}
	if (r == -1)
		read_err(argv);

	c = close(fd);
	if (c == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	c = close(fd1);
	if (c == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd1);
		exit(100);
	}
	return (0);
}
