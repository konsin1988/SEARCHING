#include <stdlib.h>
#include "struct_subarray.h"

SUBARRAY** allocate_subarr(size_t n)
{
	SUBARRAY** subarr = (SUBARRAY**)malloc(n * sizeof(SUBARRAY*) 
			+ n * sizeof(SUBARRAY));
	SUBARRAY* start = (SUBARRAY*)((char*)subarr + n * sizeof(SUBARRAY*));
	for(size_t i=0; i<n; ++i)
		subarr[i] = start + i;
	return subarr;
}
