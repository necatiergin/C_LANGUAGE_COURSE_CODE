#include <stdio.h>

int main(void)
{
	int a[5][10];

	printf("sizeof(a)       = %zu\n", sizeof(a));
	printf("sizeof(a[0])    = %zu\n", sizeof(a[0]));
	printf("sizeof(a[0][0]) = %zu\n", sizeof(a[0][0]));
}
