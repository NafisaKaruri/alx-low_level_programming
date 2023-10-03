#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2d grid created by alloc_grid
 * @grid: the 2d grid
 * @height: the grid height
 */
void free_grid(int **grid, int height)
{
	int j;

	for (j = 0; j < height; j++)
	{
		free(grid[j]);
	}
	free(grid);
}
