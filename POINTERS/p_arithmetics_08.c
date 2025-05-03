#include <stdio.h>

int main()
{
	int ar[] = { 2, 4, 6, 8 };
	int* p = ar;

	*p++ = 13;
	(*p)++;
	*++p;
	++*p;

	for (int i = 0; i < 4; ++i) {
		printf("%d ", ar[i]);
	}
}
