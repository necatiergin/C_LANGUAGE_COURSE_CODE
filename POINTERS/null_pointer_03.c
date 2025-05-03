#include <stdio.h>

int main(void)
{
	int x = 24;

	int* p1 = NULL;
	int* p2 = &x;

	if (p1 == p2)
		printf("dogru\n");
	else
		printf("yanlis\n");

	p2 = NULL;

	if (p1 == p2)
		printf("dogru\n");
	else
		printf("yanlis\n");
}
