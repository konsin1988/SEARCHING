#include <stdlib.h>
#include <time.h>

void fill_arr(int* arr, size_t n, int START, int END)
{
	srand(time(NULL));
	for(size_t i=0; i<n; ++i)
		arr[i] = rand()%(END - START) + START;
}
