#include "std.h"

/************** load database function *********/
void load_fl_db_func( load_fl_db_iface_ptr ptr )
{
	FILE *F;
	if( (F = fopen("flights.dat", "rt")) == NULL )
	{
		fprintf(stderr, "Unable to open 'flights.dat'\n");
		return;
	}
	fl_db_ptr casted_ptr = load_fl_db_to_fl_db( ptr );

	fscanf(F, "%d\n", &(*casted_ptr).fl_list_num );
	for(size_t i=0; i<(*casted_ptr).fl_list_num; ++i)
	{
		fscanf( F, "%s", 
				&(*casted_ptr).fl_list[i].from );
		fscanf( F, "%s", &(*casted_ptr).fl_list[i].to );
		fscanf( F, "%d", &(*casted_ptr).fl_list[i].distance );
	}
	
	fclose(F);
}
/*______________________________________________*/
//
/***************** match function *****************/
int match( fl_db_ptr casted_ptr, char* from, char* to )
{
	register int i;

	for( i=(*casted_ptr).fl_list_num; i>-1; --i)
	{
		if( !strcmp( (*casted_ptr).fl_list[i].from, from ) && 
		!strcmp( (*casted_ptr).fl_list[i].to, to ))
		{
			(*casted_ptr).find_pos = i;
			return (*casted_ptr).fl_list[i].distance;
		}
	} 
	/* if there is no fly from search_from 
	 * to search_to */
	return 0; 
}

/* knowing the point of departure (the from parameter),
 * find the point of arrival (anywhere parameter) ***/
/***************** find function ***********************/
int find( fl_db_ptr casted_ptr, char* from, char* anywhere )
{
	(*casted_ptr).find_pos=0;
	while( (*casted_ptr).find_pos < (*casted_ptr).fl_list_num )
	{
		if( !strcmp( 
		(*casted_ptr).fl_list[(*casted_ptr).find_pos].from, from ) && 
		!(*casted_ptr).fl_list[(*casted_ptr).find_pos].skip )
		{
			strcpy(anywhere, 
			(*casted_ptr).fl_list[(*casted_ptr).find_pos].to);
			(*casted_ptr).fl_list[(*casted_ptr).
				find_pos].skip = 1;
			return (*casted_ptr).fl_list[(*casted_ptr).
				find_pos].distance;
		}
		(*casted_ptr).find_pos ++;
	}
	return 0;
}	
/*________________________________________________________*/
//
/************  push and pop to the stack ****************/
void push( fl_db_ptr casted_ptr, char* from, char* to, int dist )
{
	if( (*casted_ptr).stack_pos < 10)
	{
		strcpy( (*casted_ptr).fl_stack[(*casted_ptr).stack_pos].from,
				from);
		strcpy( (*casted_ptr).fl_stack[(*casted_ptr).stack_pos].to, 
				to );
		(*casted_ptr).fl_stack[(*casted_ptr).stack_pos].distance = 
			dist;
		(*casted_ptr).fl_stack[(*casted_ptr).stack_pos].result_pos =
			(*casted_ptr).find_pos;
	       	(*casted_ptr).stack_pos++;
	}
	else 
		printf("Stack overflow!\n");
}

void pop( fl_db_ptr casted_ptr, char* from, char* to, int* dist )
{
	if( (*casted_ptr).stack_pos > 0 )
	{
		(*casted_ptr).stack_pos--;
		strcpy( from, 
		(*casted_ptr).fl_stack[(*casted_ptr).stack_pos].from );
		strcpy( to, 
		(*casted_ptr).fl_stack[(*casted_ptr).stack_pos].to );
		*dist = 
		(*casted_ptr).fl_stack[(*casted_ptr).stack_pos].distance;
	}
	else printf("Stack is empty!\n");
}
/*______________________________________________________*/
//
/************** isflight function **********************/
void isflight( fl_db_ptr casted_ptr, char* from, char* to )
{
	int d, dist;
	char* anywhere = (char*)malloc(25 * sizeof(char));
	/* is there the fly from search_from to search_to */
	if( d=match( casted_ptr, from, to ) )
	{
		push( casted_ptr, from, to, d );
		return;
	}
	
	/* check another fly  */
	if( dist=find( casted_ptr, from, anywhere ) )
	{
		push( casted_ptr, from, to, dist );
		isflight( casted_ptr, anywhere, to );
	}
	else if( (*casted_ptr).stack_pos > 0 )
	{
		pop(casted_ptr, from, to, &dist);
		isflight(casted_ptr, from, to);
	}

}

void search_in_depth_func( search_in_depth_iface_ptr ptr )
{
	fl_db_ptr casted_ptr = search_in_depth_to_fl_db( ptr );
	char* from = (char*)malloc(25*sizeof(char));
	char* to = (char*)malloc(25*sizeof(char));
	strcpy(from, (*casted_ptr).search_from);
	strcpy(to, (*casted_ptr).search_to);
	isflight( casted_ptr, from, to );



}
/*________________________________________________*/
//
/****************** print_result function *********/
void print_result_func( print_result_iface_ptr ptr )
{
	fl_db_ptr casted_ptr = print_result_to_fl_db( ptr );
	int distance = 0;
	int i;
	for( i=0; i<(*casted_ptr).stack_pos; ++i )
	{
		printf("%d. ", i+1);
		printf("From %s ", 
	(*casted_ptr).fl_list[(*casted_ptr).fl_stack[i].result_pos].from);
		printf("to %s ", 
	(*casted_ptr).fl_list[(*casted_ptr).fl_stack[i].result_pos].to );
		printf("is %d miles.\n", 
			(*casted_ptr).fl_stack[i].distance ); 
		distance += (*casted_ptr).fl_stack[i].distance;
	}
	printf("\nFrom %s to %s summ distance = %d.\n", 
	(*casted_ptr).search_from, (*casted_ptr).search_to, distance );
}
/*__________________________________________________*/


