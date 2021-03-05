obj=flight_func.o std.o in_param.o print_help.o db_struct.o type_casting_func.o
search_in_breadth: main.c $(obj)
	gcc $^ -o $@ -lm

clean:
	rm *.o

run: search_in_breadth
	./search_in_breadth
	
