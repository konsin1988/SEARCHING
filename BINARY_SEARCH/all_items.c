#include <stdlib.h>

#include "binary_search.h"
#include "struct_all_of.h"

void all_items(int* arr, size_t n, int num_found, ALL* left_right)
{
	size_t index = binary_search(arr, 0, n, num_found);
	while(arr[index] == num_found)
		--index;
	++index;
	(*left_right).left = index;
	while(arr[index] == num_found)
		++index;
	(*left_right).right = index - 1;
	


}
