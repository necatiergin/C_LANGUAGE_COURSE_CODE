#include <stdio.h>

int main()
{
	char str[100];

	printf("enter your name: ");
	scanf("%[^\n]s", str); //necati ergin
	printf("[%s]\n", str); // [necati ergin]
	int c = getchar();
	printf("c = %d\n", c); //10
}
