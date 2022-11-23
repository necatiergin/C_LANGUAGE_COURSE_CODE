#include <stdio.h>
#include <string.h>

int icmp(const void* vp1, const void* vp2)
{
	int i1 = *(const int*)vp1;
	int i2 = *(const int*)vp2;

	return i1 > i2 ? 1 :
		i1 < i2 ? -1 : 0;
}

//memory leak
int get_median(const int* p, size_t size)
{
	int* pd = (int*) malloc(size * sizeof(int));
	//...
	memcpy(pd, p, size * sizeof(int));
	qsort(pd, size, *pd, &icmp);

	return pd[size / 2];
}
