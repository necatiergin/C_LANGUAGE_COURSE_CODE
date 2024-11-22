//xor swap

#include <stdio.h>

int main(void)
{
	int x, y;

	printf("enter to integers: ");
	(void)scanf("%d%d", &x, &y);

	printf("x = %d y = %d\n", x, y);
	x ^= y, y ^= x, x ^= y;

	printf("x = %d y = %d\n", x, y);
};
