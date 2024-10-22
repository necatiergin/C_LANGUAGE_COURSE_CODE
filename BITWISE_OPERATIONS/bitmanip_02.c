//to set a bit

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
	unsigned int x = 0;

	printf("enter the index of the bit to set: ");
	int n;
	(void)scanf("%d", &n);

	x |= 1u << n;
	printf("x = %u\n", x);
	bit_print(x);
};
	

