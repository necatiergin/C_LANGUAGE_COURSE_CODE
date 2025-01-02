#include <stdio.h>

int main(void)
{
	char str[100] = "";

	printf("bir yazi girin: ");
	int n = scanf("%[^\n]s", str);

	printf("n = %d\n", n);
	printf("(%s)\n", str);
}
