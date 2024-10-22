#include <stdio.h>

void foo(int);

int main(void)
{
	int x, y;

	printf("iki sayi giriniz: ");
	(void)scanf("%d%d", &x, &y);

	if (x > y)
		foo(x);
	else
	   foo(y);

    //foo(x > y ? x : y);
}
