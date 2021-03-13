#include <stddef.h>

#include "struct_subarray.h"
#include "max_subarray.h"

SUBARRAY find_max_subarray(int* arr, size_t low, size_t high)
{
	SUBARRAY left, middle, right;

	if(high == low)
	{
		middle.low = low;
		middle.high = high;
		middle.sum = arr[low];
		return middle;
	}
	else
	{
		size_t mid = (low + high) / 2;
		left = find_max_subarray(arr, low, mid);
		right = find_max_subarray(arr, mid+1, high);
		middle = find_cross_subarray(arr, 
			low, mid, high);
		if(left.sum > middle.sum && left.sum > right.sum)
			return left;
		else if(right.sum > middle.sum && right.sum > left.sum)
			return right;
		else return middle;
	}


}
