#include <stdio.h>
#include <stddef.h>

void fill_manually(int* arr, size_t n)
{
	printf("\nEnter items:\n");
	for(size_t i=0; i<n; ++i)
		scanf("%d", &arr[i]);
}
