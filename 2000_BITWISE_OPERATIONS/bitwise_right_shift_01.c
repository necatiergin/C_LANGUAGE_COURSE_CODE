#include <stdio.h>
#include <limits.h>

void Bit_print(int x)
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
	unsigned int x = INT_MIN;

	while (x) {
		Bit_print(x);
		x >>= 1;
	}
}
