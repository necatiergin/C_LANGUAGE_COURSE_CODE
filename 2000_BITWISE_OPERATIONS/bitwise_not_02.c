#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

void bprint(int val)
{
	for (int i = (int)(sizeof(int) * CHAR_BIT - 1); i >= 0; --i) {
		putchar((val >> i) & 1 ? '1' : '0');
	}
	putchar('\n');
}

int main(void)
{
	int x;
	printf("bir tamsayi girin: ");
	(void)scanf("%d", &x);

	bprint(x);
	bprint(~x);
	bprint(~~x);
	printf("x = %d\n", x); //bitsel degil operatörünün yan etkisi yok
}
