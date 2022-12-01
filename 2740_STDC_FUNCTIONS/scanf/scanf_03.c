#include<stdio.h>

int main(void)
{
	char str[100];

	printf("Enter your name: ");
	scanf("%[^i]s", str); //necati ergin
	printf("name: [%s]", str);
}
