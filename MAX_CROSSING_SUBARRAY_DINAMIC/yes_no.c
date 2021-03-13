#include <stdio.h>
#include "my_getch.h"

int yes_no(char* str)
{
	printf("\nDo you want to %s array?(y/n)\n", str);
	char key = my_getch();
	while(1)
	{
		if(key == 'y')
			return 1;
		else if(key == 'n')
			return 0;
		else
		{	
			printf("\t!!!Press 'y' or 'n' for continue!!!\n");
			key = my_getch();
			continue;
		}
	}
}
