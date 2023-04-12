//ekran çıktısı ne olur?

#include <stdio.h>

#define   asize(x)    (sizeof(x) / sizeof(x[0]))

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5 };

	for (int i = -1; i < asize(a) - 1; ++i)
		printf("%d ", a[i + 1]);
}
