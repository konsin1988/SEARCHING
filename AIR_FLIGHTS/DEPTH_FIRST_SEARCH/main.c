#include "std.h"

/***** Number of cities in list ****/
#define N 8

/****** all cities ***************/
char* cities[N] = {
	"New_York", 
	"Chicago", 
	"Denver", 
	"Toronto", 
	"Calgary", 
	"Los_Angeles", 
	"Urbana", 
	"Housten" 
};
/*________________________________*/

int main(int argc, char** argv)
{
	if( in_param(argc, argv, cities) )
	{
		FL_DB flight_data = database_init( argv );
		flight_data.load_fl_db( fl_db_to_load_fl_db( &flight_data ));
		
		flight_data.search_in_depth( 
			fl_db_to_search_in_depth( &flight_data ));
		/*for( size_t i=0; i<flight_data.fl_list_num; ++i )
		{
			printf("%s ", flight_data.fl_list[i].from );
			printf("%s ", flight_data.fl_list[i].to );
			printf("%d\n", flight_data.fl_list[i].distance );
		}*/
		flight_data.print_result( 
			fl_db_to_print_result( &flight_data ));
			
	}
	return 0;
}
	
