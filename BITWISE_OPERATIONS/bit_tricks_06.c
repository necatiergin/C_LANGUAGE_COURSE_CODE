#include <stdio.h>

int main()
{
	int x;

	printf("enter an integer: ");
	(void)scanf("%d", &x);

	if (x && (x & -x) == x)
		printf("power of two\n");
	else
		printf("not power of two\n");
}
