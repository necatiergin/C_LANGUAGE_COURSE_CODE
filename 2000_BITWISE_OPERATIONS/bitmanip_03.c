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


int main(void)
{
	unsigned int x = -1;

	printf("enter the index of the bit to reset: ");
	int n;
	(void)scanf("%d", &n);
	bit_print(x);
	x &= ~(1 << n);
	bit_print(x);
	printf("x = %u\n", x);
};

