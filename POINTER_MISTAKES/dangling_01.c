#include <stdio.h>

char* scan_name(void)
{
	char name[100];

	printf("enter your name: ");
	scanf("%s", name);
	return name;
}

int main(void)
{
	char* p = scan_name();
	puts(p); //ub
}
