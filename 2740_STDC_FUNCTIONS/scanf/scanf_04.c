#include<stdio.h>

int main(void)
{
	char str[100];

	printf("Enter your name: ");
	scanf("%[^0-9]s", str); //necati ergin1235  
	printf("name: [%s]", str);
}
