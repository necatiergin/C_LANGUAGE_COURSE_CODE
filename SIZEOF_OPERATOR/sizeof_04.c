#include <stdio.h>

int main(void)
{
	char s[30] = { 0 };
	int a[100] = { 0 };
	double da[40] = { 0 };

	printf("sizeof(s) = %zu\n", sizeof(s));
	printf("sizeof(a) = %zu\n", sizeof(a));
	printf("sizeof(da) = %zu\n", sizeof(da));
}
