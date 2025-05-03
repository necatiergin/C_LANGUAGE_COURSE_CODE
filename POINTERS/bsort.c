#include<stddef.h>

void bsort(int* p, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i) {
		for (size_t j = 0; j < size - 1 - i; ++j) {
			int temp = p[j];
			p[j] = p[j + 1];
			p[j + 1] = temp;
		}
	}
}
