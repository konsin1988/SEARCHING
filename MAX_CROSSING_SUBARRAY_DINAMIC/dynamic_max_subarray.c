#include <stdlib.h>
#include <stddef.h>

#include "struct_subarray.h"

SUBARRAY dynamic_max_subarray(int* arr, size_t n, SUBARRAY** subarr)
{
	if(arr[0] > 0)
	{
		(*subarr[0]).sum = arr[0];
		(*subarr[0]).low = 0;
		(*subarr[0]).high = 0;
	}
	else
	{
		(*subarr[0]).sum = 0;
		(*subarr[0]).low = 1;
		(*subarr[0]).high = 1;
	}
	SUBARRAY max;
	max.sum = arr[0];
	max.low = 0;
	max.high = 0;
	for(size_t i=1; i<n; ++i)
	{
		if(max.sum < (*subarr[i-1]).sum + arr[i])
		{
			max.sum = (*subarr[i-1]).sum + arr[i];
			max.high = i;
			max.low = (*subarr[i-1]).low;
			(*subarr[i]).sum = max.sum;
			(*subarr[i]).low = (*subarr[i-1]).low;
			(*subarr[i]).high = i;
		}
		else if((*subarr[i-1]).sum + arr[i] <= 0)
		{
			(*subarr[i]).sum = 0;
			(*subarr[i]).low = i+1;
			(*subarr[i]).high = i;
		}
		else
		{
			(*subarr[i]).sum = (*subarr[i-1]).sum + arr[i];
			(*subarr[i]).low = (*subarr[i-1]).low;
			(*subarr[i]).high = i;
		}
	}
	return max;
}
