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
	int x = 1;

	bprint(x);
	bprint(x << 1);
	bprint(x << 2);

	printf("x = %d\n", x);  //no side effect
}
