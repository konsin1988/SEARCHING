#include <stdio.h>
#include <stddef.h>
#include <string.h>

int in_param(int argc, char** argv, size_t* n, int* LOW, int* HIGH)
{
	if(argc<=1)
	{
		printf("\nSyntax:\n\t%s 'arr' 'number_of_items' "
			"'lowest_item' 'highest_item'\n", argv[0]);
	}
	else if(!strcmp(argv[1], "arr"))
	{
		if(argc != 5)
		{
			printf("\n\t%s requires three "
			"parameters.\n", argv[1]);
		}
		else if(sscanf(argv[2], "%zu", n) != 1 || sscanf(argv[3], 
		"%d", LOW) != 1 || sscanf(argv[4], "%d", HIGH) != 1)
		{
			printf("\n\t%s operation requires three integer "
			"parameters.\n", argv[1]);
		}
		else
		{
			return 1;
		}
	}
	else
	{	
		printf("\n\t***Unknown parameter!!!***\n");
	}
	
	return 0;
}
