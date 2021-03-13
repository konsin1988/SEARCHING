#include <stdio.h>
#include "my_getch.h"

#define VK_SPACE 32

void print_annotation()
{
	printf("/* An array of n int elements is created.\n/* The array consists of random elements from span (START; END).\n/* Allocate memory for N elements by function malloc.\n/* An array is sorted by merge sort function.\n/* It is possible to print or not to print initial and sorted arrays.\n");
	printf("\n\tPress SPACE to continue...");
	char key = my_getch();
	while(1)
	{
		if(key == VK_SPACE)
			return;
		else
		{
			key = my_getch();
			continue;
		}
	}
}
