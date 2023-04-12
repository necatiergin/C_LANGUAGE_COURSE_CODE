#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int c;

	printf("bir karakter girin: ");
	c = getchar();

	//printf("%c  ===> %c\n", c, toupper(c));
	printf("%c  ===> %c\n", c, tolower(c));
}
