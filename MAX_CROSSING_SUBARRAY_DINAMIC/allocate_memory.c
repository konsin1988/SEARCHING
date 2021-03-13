#include <stdlib.h>

int* allocate_memory(size_t N)
{
	int* arr = (int*)malloc(N * sizeof(int));
	return arr;
}
