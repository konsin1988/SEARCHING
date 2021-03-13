#include <stdlib.h>
#include "struct_all_of.h"

void all_items(int* arr, size_t n, int num_found, ALL* left_right);

size_t binary_search (int* arr, size_t l, size_t n, int num_found)
{
	int center = (n + l) / 2;
	if(num_found == arr[center])
		return center;
	else if(center > n - 1) 
		return -1;
	else if(num_found > arr[center])
	{
		l = center;
		binary_search(arr, l, n, num_found);	
	}
	else
	{
		n = center;
		binary_search(arr, l, n, num_found);
	}

}

