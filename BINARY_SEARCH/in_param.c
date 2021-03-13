#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in_param(int argc, char** argv, size_t* n, int* START, int* END)
{
	if(argc <= 1)
	{
		printf("Syntax:\n\t %s '--arr' 'number of elements' 'START' 'END'\n", argv[0]);
		return 0;
	}
	else
	{
		if(!strcmp(argv[1], "--arr"))
		{
			if(argc != 5)
			{
        			printf("\n\t%s needs 3 param: " 
				"number, START and END.\n");
                		return 0;
            		}
            		else if(sscanf(argv[2], "%zu", n) != 1 || sscanf(argv[3], "%d", START) != 1 || sscanf(argv[4], "%d", END) != 1)
			{
		 		printf("'--arr' operation requires three integer parameters\n");
				return 0;
			}
			else if(argv[2] <= 0)
			{
				printf("\n\tNumber of elements must be >0\n");
				return 0;
			}
			else if(argv[3] >= argv[4])
				printf("\n\tSTART must be < END.\n");
			else
					return 1;
		}
		else
		{
			printf("\n\tUnknown function!\n");
			return 0;
		}
	}
}
