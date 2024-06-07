#include <stdio.h>

int main(void)
{
	//x is either 5 or 9

	int x = 9;
	x = 9 ^ 5 ^ x;
	printf("x = %d\n", x);
	x = 5 ^ 9 ^ x;
	printf("x = %d\n", x);
	x = x ^ 9 ^ 5;
	printf("x = %d\n", x);	
	x = x ^ 9 ^ 5;
	printf("x = %d\n", x);
};

