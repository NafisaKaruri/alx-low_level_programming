#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: the lenth of s
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * create_file - creates a file
 * @filename: the name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Description: the created file must have rw------- permissions,
 * if the file already exists, do not change the permissions,
 * if the file already exists, truncate it
 * if text_content is NULL create an empty file
 *
 * Return: 1 on success, -1 on failure, -1 if filename is NULL
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int wcount;

	if (!filename)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		wcount = write(fd, text_content, _strlen(text_content));
		if (wcount == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
