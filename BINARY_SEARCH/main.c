#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "arr_work.h"
#include "print_annotation.h"
#include "in_param.h"
#include "merge_sort.h"
#include "yes_no.h"
#include "binary_search.h"
#include "struct_all_of.h"


#define N 10000
#define M 10

size_t n;
int START, END;



int main(int argc, char** argv)
{
	if(in_param(argc, argv, &n, &START, &END))
	{
		int* arr = alloc_arr(N);
		print_annotation();
		fill_arr(arr, n, START, END);
		if(yes_no("initial", "print"))
			print_arr(arr, n);
		merge_sort(arr, 0, n);
		if(yes_no("sorted", "print"))
			print_arr(arr, n);
		if(yes_no("sorted", "write"))
			write_to_file(arr, n);
		int num_found;
		
		ALL* left_right = (ALL*)malloc(sizeof(ALL));
		printf("Enter int number to search: ");
		scanf("%d", &num_found);
		printf("The index of searching number: %zu\n", 
			binary_search(arr, 0, n, num_found));
		all_items(arr, n, num_found, left_right);
		printf("The indexes of all searching numbers\n "
			"in the array is: %zu - %zu\n",
			(*left_right).left, (*left_right).right);
		free(arr);
	}

	return 0;
}




