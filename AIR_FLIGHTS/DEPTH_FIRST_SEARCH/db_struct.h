
/************* load_fl_db interface ********************/
typedef struct load_fl_db_iface* load_fl_db_iface_ptr;
typedef const char* (*load_fl_db_func_ptr)( load_fl_db_iface_ptr );

struct load_fl_db_iface
{
	load_fl_db_func_ptr load_fl_db;
};
typedef struct load_fl_db_iface load_fl_db_iface;
/*_____________________________________________________*/
//
/* *********** search_in_depth interface ************** */
typedef struct search_in_depth_iface* search_in_depth_iface_ptr;
typedef const char* (*search_in_depth_func_ptr)( search_in_depth_iface_ptr );

struct search_in_depth_iface
{
	search_in_depth_func_ptr search_in_depth;
};

typedef struct search_in_depth_iface search_in_depth_iface;
/*_________________________________________________________*/
//
//
/*************** print_result interface *******************/
typedef struct print_result_iface* print_result_iface_ptr;
typedef const char* (*print_result_func_ptr)( print_result_iface_ptr );

struct print_result_iface
{
	print_result_func_ptr print_result;
};
typedef struct print_result_iface print_result_iface;
/*_________________________________________________________*/
//
/************** Struct for one fligth **********************/
struct FL
{
	char from[24];
	char to[24];
	int distance;
	char skip;
	int result_pos;
};
typedef struct FL FL;
/* ______________________________________________________ */
//
//
/* *********** Struct for all flights *********************/
/* ********** with method 'search_in_depth' ***************/
typedef struct FL_DB* fl_db_ptr;
struct FL_DB
{
	load_fl_db_func_ptr load_fl_db;
	search_in_depth_func_ptr search_in_depth;
	print_result_func_ptr print_result;

	FL* fl_list;		/* database with all possible flies ***/
	int fl_list_num;	/* number of elements in database *****/
	FL* fl_stack;		/* stack ******************************/
	int stack_pos;		/* top of stack ***********************/
	int find_pos;		/* helper global variable for search **/
	char search_from[25];	/* start of the route *****************/
	char search_to[25];	/* end of the route *******************/

};
typedef struct FL_DB FL_DB;
/*_________________________________________________________*/
//
/************** Constructor *******************************/
FL_DB database_init( char** argv );
/*________________________________________________________*/
//
//
/****************** Manual type casting ******************/
search_in_depth_iface_ptr fl_db_to_search_in_depth( fl_db_ptr );
fl_db_ptr search_in_depth_to_fl_db( search_in_depth_iface_ptr );
load_fl_db_iface_ptr fl_db_to_load_fl_db( fl_db_ptr );
fl_db_ptr load_fl_db_to_fl_db( load_fl_db_iface_ptr );
print_result_iface_ptr fl_db_to_print_result( fl_db_ptr );
fl_db_ptr print_result_to_fl_db( print_result_iface_ptr );
/*________________________________________________________*/
//
//
/********************* In_param **************************/
int in_param( int argc, char** argv, char** cities );
void print_help( char** argv );
/*______________________________________________________*/
//
/**************** flight_data_functions ****************/
void load_fl_db_func( load_fl_db_iface_ptr );
void search_in_depth_func( search_in_depth_iface_ptr );
void print_result_func( print_result_iface_ptr );
/*_____________________________________________________*/
