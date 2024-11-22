#include <stdio.h>

int main(void)
{
	int x;

	printf("enter en integer: ");
	(void)scanf("%d", &x);

	if (x & 1) {  // integer is odd if 0th bit is set
		printf("%d is odd\n", x);
	}
	else {
		printf("%d is even\n", x);
	}
}
