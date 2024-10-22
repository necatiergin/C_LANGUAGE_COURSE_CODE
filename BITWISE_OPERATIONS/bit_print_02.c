#include <stdio.h>
#include <limits.h>

void bit_print(int x)
{
	for (int i = (int)(sizeof(int) * CHAR_BIT - 1); i >= 0; --i) {
		putchar((x >> i) & 1 ? '1' : '0');
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
