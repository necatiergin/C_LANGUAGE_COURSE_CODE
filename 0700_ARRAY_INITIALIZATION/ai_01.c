//diziye ilk değer verme (array initialization)

#include <stdio.h>

#define   SIZE   10

int main(void)
{
	int a[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < SIZE; ++i)
		printf("a[%d] = %d\n", i, a[i]);
}
