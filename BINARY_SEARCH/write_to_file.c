#include <stdio.h>

void write_to_file(int* arr, size_t n)
{
	FILE *F;

	if((F = fopen("sorted_array.dat", "wt")) == NULL)
	{
		fprintf(stderr, "Unable to open 'sorted_array.dat'!");
		return;
	}
	fprintf(F, "%zu\n", n);
	for(size_t i=0; i<n; ++i)
		fprintf(F, "%d ", arr[i]);

	fclose(F);
}
