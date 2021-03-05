#include "db_struct.h"

/**************** enum for type casting ***************/
enum
{
	num_load_fl_db_offset = 0,
	num_search_in_depth_offset = sizeof( load_fl_db_func_ptr ),
	num_print_result_offset = sizeof( load_fl_db_func_ptr ) +
		sizeof( search_in_depth_func_ptr ),
};
/*_____________________________________________________*/
//
//
/************ fl_db_to_search_in_depth type casting *******/
search_in_depth_iface_ptr fl_db_to_search_in_depth( fl_db_ptr ptr )
{
	return (search_in_depth_iface_ptr)( (char*)ptr +
		num_search_in_depth_offset );
}
/*_________________________________________________________*/
//
/************ fl_db_to_load_fl_db type casting *******/
load_fl_db_iface_ptr fl_db_to_load_fl_db( fl_db_ptr ptr )
{
	return (load_fl_db_iface_ptr)( (char*)ptr +
		num_load_fl_db_offset );
}
/*_________________________________________________________*/
//
/************ fl_db_to_print_result type casting *******/
print_result_iface_ptr fl_db_to_print_result( fl_db_ptr ptr )
{
	return (print_result_iface_ptr)( (char*)ptr +
		num_print_result_offset );
}
/*_________________________________________________________*/
//
/************ search_in_depth_to_fl_db type casting *******/
fl_db_ptr search_in_depth_to_fl_db( search_in_depth_iface_ptr ptr )
{
	return (fl_db_ptr)( (char*)ptr -
		num_search_in_depth_offset );
}
/*_________________________________________________________*/
//
/************ load_fl_db_to_fl_db type casting *******/
fl_db_ptr load_fl_db_to_fl_db( load_fl_db_iface_ptr ptr )
{
	return (fl_db_ptr)( (char*)ptr -
		num_load_fl_db_offset );
}
/*_________________________________________________________*/
//
/************ print_result_to_fl_db type casting *******/
fl_db_ptr print_result_to_fl_db( print_result_iface_ptr ptr )
{
	return (fl_db_ptr)( (char*)ptr -
		num_print_result_offset );
}
/*_________________________________________________________*/
//
