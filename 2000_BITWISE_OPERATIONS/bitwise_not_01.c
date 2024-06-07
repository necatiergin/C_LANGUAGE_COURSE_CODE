#include <stdio.h>
#include <limits.h>

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
	unsigned int x = UINT_MAX;
	unsigned int y = -1;
	unsigned int z = ~0U;

	bit_print(x);
	bit_print(y);
	bit_print(z);
}
