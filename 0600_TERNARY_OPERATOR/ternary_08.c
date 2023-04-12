#include <stdio.h>

int main(void)
{
	int max;
	int x, y;

	printf("iki sayi giriniz: ");
	(void)scanf("%d%d", &x, &y);

	if (x > y)
		max = x;
	else
		max = y;

	//int max = x > y ? x : y;
	//const int max = x > y ? x : y;
}
