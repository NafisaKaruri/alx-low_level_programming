#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: a pointer to the memory previously allocated with malloc(old_size)
 * @old_size: the size, in bytes, of the allocated space for ptr
 * @new_size: the new size, in bytes of the new memory block
 *
 * Description: The contents will be copied to the newly allocated space,
 *		in the range from the start of ptr up to the minimum of
 *		the old and new sizes.
 *		If new_size > old_size, the “added” memory should not be
 *		initialized.
 *		If new_size == old_size do not do anything and return ptr.
 *		If ptr is NULL, then the call is equivalent to malloc(new_size),
 *		for all values of old_size and new_size.
 *
 * Return:
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;

	if (new_size == old_size)
		return (ptr);
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	free(ptr);
	return (p);
}
