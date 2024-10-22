#include <stdio.h>

double foo(void)
{
	printf("necati ergin\n");
	return 4.5;
}

int main(void)
{
	int x = 3;

	printf("%zu", sizeof(x++));
	printf("%d", x);
	printf("%zu", sizeof(foo())); //foo işlevi çağrılmayacak
}
