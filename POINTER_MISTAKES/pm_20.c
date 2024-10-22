#include <stdio.h>

int main(void)
{
	int x;
	int* p = &x;
	printf("bir tam sayi girin: ");
	scanf("%d", *p); //ub
	//...
}
