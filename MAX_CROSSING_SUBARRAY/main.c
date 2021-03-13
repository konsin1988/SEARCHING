#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "in_param.h"
#include "arr_form.h"
#include "yes_no.h"
#include "struct_subarray.h"
#include "max_subarray.h"

#define N 1000

size_t n;
int LOW, HIGH;

int main(int argc, char** argv)
{
	if(in_param(argc, argv, &n, &LOW, &HIGH))
	{
		int* arr = allocate_memory(N);
		random_fill_arr(arr, n, LOW, HIGH);
		if(yes_no("print"))
			print_arr(arr, n);
		if(yes_no("save"))
		{
			if(save_arr(arr, n))
				printf("\n***Saving done "
				"successfully!**\n\n");
		}
		SUBARRAY result = find_max_subarray(arr, 0, n);
		printf("\n%zu\t%zu\t%d\n", result.low, 
			result.high, result.sum);

	}


	return 0;
}
