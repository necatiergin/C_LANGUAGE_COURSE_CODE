#include <stdio.h>

int main()
{
	int x = 10;

	int* p1 = &x, *p2 = p1, *p3 = p2;

	++*p1;
	++*p2;
	++*p3;

	printf("x = %d\n", x);
}
