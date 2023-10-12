#include "variadic_functions.h"

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
	int i = 0, j;
	char *a, *b = "cifs";

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
				a = va_arg(ap, char *);
				printf("%s", a ? a : "(nil)");
				break;
			default:
				break;
		}
		i++;
		if (format[i])
		{
			j = 0;
			while (b[j])
			{
				if (format[i] == b[j])
				{
					printf(", ");
					break;
				}
				j++;
			}
		}
	}
	printf("\n");
	va_end(ap);
}
