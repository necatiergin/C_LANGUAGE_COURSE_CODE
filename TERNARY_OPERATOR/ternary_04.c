#include <stdio.h>

//sequence point

int g = 10;

int f1(void)
{
	g = 987;

	return 0;
}

int main(void)
{
	int a = f1() ? g : g - 900;

	printf("a = %d\n", a);
}
