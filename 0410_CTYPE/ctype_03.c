#include <stdio.h>
#include <ctype.h>

//case-insensitive karşılaştırma

int main(void)
{
	int c1, c2;

	printf("iki karakter giriniz: ");
	c1 = getchar();
	c2 = getchar();

	if (toupper(c1) == toupper(c2)) {
		printf("%c ve %c ayni karakterler\n", c1, c2);
	}
	else {
		printf("%c ve %c farkli karakterler\n", c1, c2);
	}
}
