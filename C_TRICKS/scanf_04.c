#include <stdio.h>

int main(void)
{
	char str[100];

	printf("bir yazi girin: ");
	scanf("%*d%s", str); //3456necati
	printf("str = %s\n", str);
}
