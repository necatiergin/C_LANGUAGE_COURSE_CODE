#include <stdio.h>

int main(void)
{
	int width = 12;
	char str[] = "necati";

	int i = 234;

	printf("%*d%s\n", width, i, str);
	printf("%-*d%s\n", width, i, str);
}
