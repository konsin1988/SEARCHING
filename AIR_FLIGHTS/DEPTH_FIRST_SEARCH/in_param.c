#include "std.h"

int in_param(int argc, char** argv, char** cities)
{
	int flag = 0;
	if(argc<=1)
	{

		printf("\n\t%s requires two arguments.\n"
			"\t%s --help  : for more information,\n"
			"\t%s --all : to see all flights.\n", 
			argv[0], argv[0], argv[0]);
	}
	else if(!strcmp(argv[1], "--help"))
	{
		print_help(argv);
	}
	else if(!strcmp(argv[1], "--all"))
	{
		system("cat flights.dat");
	}
	else if( argc != 3 )
	{
		printf("%s requires two parameters\n"
			"See  --help for information,\n"
			"\t--all to see all flights\n", argv[0]);
	}
	else
	{
		for(size_t i=0; cities[i]; ++i)
		{
			if(!strcmp(argv[1], cities[i]) || 
				!strcmp(argv[2], cities[i]))
			{
				++flag;
			}
		}
		if( flag < 2 )
		{
			printf("There is no cities in the list\n");
		}
		else return 1;
	}
	return 0;
}

