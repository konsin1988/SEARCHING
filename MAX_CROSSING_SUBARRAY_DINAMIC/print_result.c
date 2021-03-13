#include <stdio.h>
#include "my_getch.h"


void print_result(char* name, int sum, size_t low, size_t high)
{
	printf("\nResult of %s search:\n\tMax sum = "
		"%d\n\ti_low = %zu\n\ti_high = %zu\n", name, sum, low, high);
	printf("\n\t***PRESS ANY KEY TO CONTINUE..***\n");
	my_getch();
}
