#include <stdio.h>

int main(void)
{
	int a[] = { 2, 5, 7, 8, 2, 1, 9, 5, 76, 10, 20, 30, 40 };

	for (unsigned i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
		printf("%d ", a[i]);
	}
}
