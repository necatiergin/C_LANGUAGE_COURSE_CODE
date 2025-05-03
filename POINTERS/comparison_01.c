#include <stdio.h>

int main(void)
{
	int x = 10, y = 45;

	int* p1 = &x, * p2 = &y;

	if (p1 == p2) {
		printf("equal\n");
	}
	else {
		printf("not equal\n");
	}

	p2 = &x;

	if (p1 == p2) {
		printf("equal\n");
	}
	else {
		printf("not equal\n");
	}
}
