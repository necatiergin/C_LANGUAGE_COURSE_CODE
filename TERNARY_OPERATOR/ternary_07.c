#include <stdio.h>

int func(int a)
{
	//...
	return a == 5 ? 20 :
		a == 13 ? 30 :
		a == 27 ? 50 : 90;
}


int main(void)
{
	printf("%d\n", func(5));
	printf("%d\n", func(13));
	printf("%d\n", func(27));
	printf("%d\n", func(88));
}
