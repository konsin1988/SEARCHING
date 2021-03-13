#include <stddef.h>
#include "struct_subarray.h"
#include <math.h>

SUBARRAY find_cross_subarray(int* arr, int low, int mid, int high)
{
	SUBARRAY max;

	int left_sum = -1000000;
	int sum = 0;
	for(size_t i=mid; i>low; --i)
	{
		sum = sum + arr[i];
		if(sum > left_sum)
		{
			left_sum = sum;
			max.low = i;
		}
	}
	int right_sum = -1000000 ;
	sum = 0;
	for(size_t i=mid+1; i<high; ++i)
	{
		sum = sum + arr[i];
		if(sum > right_sum)
		{
			right_sum = sum;
			max.high = i;
		}

	}
	max.sum = left_sum + right_sum;
	return max;
}
