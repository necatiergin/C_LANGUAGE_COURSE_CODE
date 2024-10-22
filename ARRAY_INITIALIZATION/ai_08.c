#include <stdio.h>

//C dilinin 99 standartları ile (C99)
// dile eklenen "designated initializer" sentaksı 

int main(void)
{
	int a[20] = {[3] = 3, [7] = 43, [16] = 9, [10] = 1}; 

	for (int i = 0; i < 20; ++i) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}
