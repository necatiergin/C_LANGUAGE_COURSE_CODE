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


int main()
{
	bit_print(~(~0u << 5));
	bit_print(~(~0u << 9));
	bit_print(~(~0u << 13));
}
