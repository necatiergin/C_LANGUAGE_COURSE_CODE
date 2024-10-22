#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

void bit_print(unsigned int x)
{
	unsigned int mask = ~(~0u >> 1);

	while (mask) {
		putchar(x & mask ? '1' : '0');
		mask >>= 1;
	}
	putchar('\n');
}

void main(void)
{
	int x, y;

	printf("enter two integers: ");
	(void)scanf("%d%d", &x, &y);
	printf("x     = ");
	bit_print(x);
	printf("y     = ");
	bit_print(y);
	printf("x ^ y = ");
	bit_print(x ^ y);
}
