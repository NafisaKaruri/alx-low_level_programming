#include <stdlib.h>

int rand(void)
{
	static int winner[] = {9, 8, 10, 24, 75, 9};
	static int i = 0;

	return winner[i++];
}
