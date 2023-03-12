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

void main(void)
{
	int ival;

	printf("bir tam sayi giriniz: ");
	(void)scanf("%d", &ival);
	bit_print(ival);
}
