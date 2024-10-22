#include <stdlib.h>

int main(void)
{
	int a[10] = { 1, 2, 5, 7, 9, 3, 9, 12, 4, 6 };
	int* p = a;
	int(*pa)[10] = &a;

	//we want to allocate a storage and copy the array a there
	// mark the incorrect declarations.

	int* p1 = (int*)malloc(sizeof(p));
	int* p2 = (int*)malloc(sizeof(*p));
	int* p3 = (int*)malloc(sizeof(a));
	int* p4 = (int*)malloc(sizeof(pa));
	int* p5 = (int*)malloc(sizeof(*pa));
}
