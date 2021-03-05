#include <string.h>
#include "std.h"

/********** constructor FL_DB ********************/

FL_DB database_init( char** argv )
{
	FL_DB flight_data;
	FL* fl_list = (FL*)malloc(20 * sizeof(FL));
	FL* fl_stack = (FL*)malloc(10 * sizeof(FL));

	flight_data.load_fl_db = (load_fl_db_func_ptr)load_fl_db_func;
	flight_data.search_in_depth = 
		(search_in_depth_func_ptr)search_in_depth_func;
	flight_data.print_result = (print_result_func_ptr)print_result_func;

	flight_data.fl_list = fl_list;
	flight_data.fl_stack = fl_stack;
	flight_data.stack_pos = 0;
	flight_data.find_pos = 0;
	strcpy(flight_data.search_from, argv[1]);
	strcpy(flight_data.search_to, argv[2]);

	return flight_data;

}
