0#include <stdio.h>

int main(void)
{
	int x = 0x7654ABCD;
	unsigned short y;

	y = x;

	printf("y = %X\n", y); //ABCD
}
