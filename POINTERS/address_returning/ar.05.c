#include <stddef.h>

int* get_array_max(const int* ptr, size_t size)
{
	const int* pmax = ptr;

	for (size_t i = 1; i < size; ++i) {
		if (ptr[i] > *pmax) {
			pmax = ptr + i;
		}
	}

	return (int*)pmax;
}


int* get_array_min(const int* ptr, size_t size)
{
	const int* pmin = ptr;

	for (size_t i = 1; i < size; ++i) {
		if (ptr[i] < *pmin) {
			pmin = ptr + i;
		}
	}
	return (int*)pmin;
}
