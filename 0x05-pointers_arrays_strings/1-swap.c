#include "main.h"

/**
 * swap_int - swaps the valuse of two integers
 * @a: pointer to integer to be swapped
 * @b: pointer to the second integer to be swapped
 */
void swap_int(int *a, int *b)
{
	int s;

	s = *a;
	*a = *b;
	*b = s;
}
