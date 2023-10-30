#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: the length of s
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 *
 * Description: do not create the file if it does not exist,
 *		if the text_content is null, do not add anything
 *
 * Return: 1 on success and -1 on failure
 *	-  1 if the file exists, -1 if the file does not exist,
 *	-  -1 if you do not have the required permissions to write
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int wcount;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND, 0600);
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
