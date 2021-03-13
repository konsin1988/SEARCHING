#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_getch.h"

int yes_no(char* str, char* func)
{
	printf("\n\tDo you want to %s %s array?(y/n)\n", func, str);
	char key = my_getch();
	while(1)
	{
		if(key == 'y')
			return 1;
		else if(key == 'n')
			return 0;
		else
		{	
			printf("\t>>>Press y/n for continue!\n");
			key = my_getch();
			continue;
		}
	}
}
