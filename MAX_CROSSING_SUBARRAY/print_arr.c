#include <stdio.h>

void print_arr(int* arr, size_t n)
{
	printf("*\t*\t*\t*\n");
	for(size_t i=0; i<n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
