#include <stdio.h>

int main(void)
{
	int x = 10;

	//x = ~-x;
	x = -~x;

	printf("x = %d\n", x);
}
