#include <time.h>
#include <stddef.h>
#include <stdlib.h>

void random_fill_arr(int* arr, size_t n, int LOW, int HIGH)
{
	srand(time(NULL));
	for(size_t i=0; i<n; ++i)
	{
		arr[i] = rand()%(HIGH - LOW) + LOW;
	}
}
