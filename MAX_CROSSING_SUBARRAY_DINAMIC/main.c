#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "in_param.h"
#include "arr_form.h"
#include "yes_no.h"
#include "struct_subarray.h"
#include "search_subarray.h"
#include "max_subarray.h"

#define N 1000

size_t n;
int LOW, HIGH;

int main(int argc, char** argv)
{
	if(in_param(argc, argv, &n, &LOW, &HIGH))
	{
		int* arr = allocate_memory(N);
		if(yes_no("fill random"))
			random_fill_arr(arr, n, LOW, HIGH);
		else 
			fill_manually(arr, n);
		if(yes_no("print"))
			print_arr(arr, n);
		SUBARRAY** subarr = allocate_subarr(n);
		SUBARRAY dynamic = dynamic_max_subarray(arr, n, subarr);
		print_result("dynamic", dynamic.sum, 
			dynamic.low, dynamic.high);
		SUBARRAY result = find_max_subarray(arr, 0, n);
		print_result("recursion", result.sum, 
			result.low, result.high);	
	}


	return 0;
}
