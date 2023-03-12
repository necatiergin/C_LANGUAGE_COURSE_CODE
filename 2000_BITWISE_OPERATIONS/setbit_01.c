#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void bit_print(int x)
{
	unsigned int mask = ~(~0u >> 1);

	while (mask) {
		putchar(x & mask ? '1' : '0');
		mask >>= 1;
	}
	putchar('\n');
}


int main(void)
{
	unsigned int x = 0;

	printf("kacinci biti set edelim: ");
	int n;
	(void)scanf("%d", &n);

	x |= 1 << n;
	printf("x = %u\n", x);
	bit_print(x);
};
	

