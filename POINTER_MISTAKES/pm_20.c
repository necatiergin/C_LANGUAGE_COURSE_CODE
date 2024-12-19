#include <stdio.h>

int main(void)
{
	int x;
	int* p = &x;
	printf("enter an integer : ");
	scanf("%d", *p); //ub  (p not *p)
	//...
}
