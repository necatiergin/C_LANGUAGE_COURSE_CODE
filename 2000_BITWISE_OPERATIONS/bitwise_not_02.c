#include <stdio.h>
#include <limits.h>

void bprint(int val)
{
	for (int i = (int)(sizeof(int) * CHAR_BIT - 1); i >= 0; --i) {
		putchar((val >> i) & 1 ? '1' : '0');
	}
	putchar('\n');
}

int main(void)
{
	int x;
	printf("enter an integer: ");
	(void)scanf("%d", &x);

	bprint(x);
	bprint(~x);
	bprint(~~x);
	printf("x = %d\n", x); //bitwise not operator has no side effect
}
