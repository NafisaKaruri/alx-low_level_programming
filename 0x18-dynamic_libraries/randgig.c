#include <stdlib.h>

int rand(void)
{
	static int winner[] = {9, 8, 10, 24, 75, 9};
	static int i = 0;

	if (i < 6)
		return winner[i++];
	else
		return 0;
}
