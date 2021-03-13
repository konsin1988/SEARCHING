#include <stddef.h>
#include "struct_subarray.h"

SUBARRAY** allocate_subarr(size_t n);
SUBARRAY dynamic_max_subarray(int* arr, size_t n, SUBARRAY** subarr);
