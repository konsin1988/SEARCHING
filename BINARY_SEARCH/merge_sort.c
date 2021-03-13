#include <stddef.h>
#include "arr_work.h"
#include <math.h>
#include "stdio.h"


void merge(int* arr, size_t p, size_t q, size_t r)
{
	size_t n1 = q - p;
	size_t n2 = r - q;
	int* L = alloc_arr(n1 + 1);
	int* R = alloc_arr(n2 + 1);
	for(size_t i = 0; i<n1; ++i)
		L[i] = arr[p + i];
	for(size_t j=0; j<n2; ++j)
		R[j] = arr[q + j];
	L[n1] = (int)INFINITY;
	R[n2] = (int)INFINITY;
	size_t i = 0, j = 0;
	for(size_t k = p; k < r; ++k)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			++i;
		}
		else
		{
			arr[k] = R[j];
			++j;
		}
	}
}

void merge_sort(int* arr, size_t p, size_t r)
{
	if(p<r-1)
	{
		size_t q;
		q = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q, r);
		merge(arr, p, q, r);
	}
}
