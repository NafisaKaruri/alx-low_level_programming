#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: name of the person
 * @f: the function to show the style of the printing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f)
		f(name);
}
