#include "variadic_functions.h"

/**
 * _strcmp - searchs if a character is in a string
 * @c: the character
 * @s: the string to be searched
 *
 * Return: 1 if c is found in s, otherwise 0
 */
int _strcmp(char c, char *s)
{
	int j = 0;

	while (s[j])
	{
		if (c == s[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}

/**
 * print_all - prints anything
 * @format: the list of types of arguments passed
 *		c: char
 *		i: integer
 *		f: float
 *		s: char *
 *		anything else can be ignored
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0;
	char *s, *f = "cifs";

	va_start(ap, format);
	while (format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(ap, int));
				break;
			case 'i':
				printf("%d", va_arg(ap, int));
				break;
			case 'f':
				printf("%f", va_arg(ap, double));
				break;
			case 's':
				s = va_arg(ap, char *);
				printf("%s", s ? s : "(nil)");
				break;
			default:
				break;
		}
		i++;
		if (format[i] && _strcmp(format[i], f))
			printf(", ");
	}
	printf("\n");
	va_end(ap);
}
