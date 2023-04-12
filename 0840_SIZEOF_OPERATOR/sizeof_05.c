#include <stdio.h>

int main(void)
{
	char s[30] = { 0 };
	int a[100] = { 0 };
	double da[40] = { 0 };


	printf("boyut s = %zu\n", sizeof(s) / sizeof(s[0]));
	printf("boyut a = %zu\n", sizeof(a) / sizeof(a[0]));
	printf("boyut da = %zu\n", sizeof(da) / sizeof(da[0]));
}
