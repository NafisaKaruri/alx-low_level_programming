#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2d array of integers
 * @width: the width of the array
 * @height: the height of the array
 *
 * Return: NULL if width or height is 0,
 *		NULL on failure, pointer to array otherwise
 */
int **alloc_grid(int width, int height)
{
	int **s;
	int i, j;

	if (width == 0 || height == 0)
	{
		return (NULL);
	}
	s = malloc(sizeof(int *) * height);
	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		s[i] = malloc(sizeof(int) * width);
		if (s[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(s[j]);
			}
			free(s);
			return (NULL);
		}
		for (j = 0; j < width; j++)
		{
			s[i][j] = 0;
		}
	}
	return (s);
}
