#include <stdio.h>

int main(void)
{
	int x = 10;
	int a = 5;
	double b = 4.5;

	printf("%zu\n", sizeof 'A');
	printf("%zu\n", sizeof(x));
	printf("%zu\n", sizeof(b));
	printf("%zu\n", sizeof(x * b));
	printf("%zu\n", sizeof(x > 0 ? a : b));
}
