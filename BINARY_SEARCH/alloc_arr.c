#include <stdlib.h>

int* alloc_arr(size_t N)
{
	int* arr = (int*)malloc(N * sizeof(int));
	return arr;
}
