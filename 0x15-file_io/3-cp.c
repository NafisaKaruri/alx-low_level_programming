#include "main.h"
#include <sys/stat.h>
/**
 * _close - close fd and exit if not closed
 * @fd: the file descriptor
 */
void _close(int fd)
{
	int c = close(fd);

	if (c == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

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
 * _strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 0 if no differences
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
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
	int fd, fd1, r, wcount;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	if (_strcmp(argv[1], argv[2]) == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		read_err(argv);

	fd1 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd1 == -1)
	{
		_close(fd);
		write_err(argv);
	}
	while ((r = read(fd, buffer, 1024)) > 0)
	{
		wcount = write(fd1, buffer, r);
		if (wcount != r)
		{
			_close(fd);
			_close(fd1);
			write_err(argv);
		}
	}
	if (r == -1)
	{
		_close(fd);
		_close(fd1);
		read_err(argv);
	}
	_close(fd);
	_close(fd1);
	return (0);
}
