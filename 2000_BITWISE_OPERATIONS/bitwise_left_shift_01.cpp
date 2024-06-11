#include <stdio.h>
#include <limits.h>

void bprint(unsigned int val)
{
	for (int i = (int)(sizeof(int) * CHAR_BIT - 1); i >= 0; --i) {
		putchar((val >> i) & 1 ? '1' : '0');
	}
	putchar('\n');
}


int main(void)
{
	unsigned int x = 1;
	
	printf("x = %zu\n", x);  

	bprint(x);
	bprint(x << 1);
	bprint(x << 2);

	printf("x = %zu\n", x);  //no side effect
}
