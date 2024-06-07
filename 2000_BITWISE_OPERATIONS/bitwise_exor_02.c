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
	int x;

	printf("enter an integer: ");
	scanf("%d", &x);

	printf("%d\n", x ^ x);

	bit_print(x);
	bit_print(x);
	bit_print(x ^ x);
};
