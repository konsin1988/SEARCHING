#include <stdio.h>

int save_arr(int* arr, size_t n)
{
	FILE* F;

	if((F = fopen("file_saving.dat", "wt")) == NULL)
	{
		fprintf(stderr, "\n!!!Unable to open 'file_saving.dat'!!!\n");
		return 0;
	}
	fprintf(F, "%zu\n", n);
	for(size_t i=0; i<n; ++i)
		fprintf(F, "%d ", arr[i]);
	fprintf(F, "%s\n", "");

	fclose(F);
	return 1;
}
