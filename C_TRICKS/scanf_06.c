#include <stdio.h>

int main(void)
{
	int d, m, y;

	printf("tarihi girin: ");
	scanf("%d%*c%d%*c%d", &d, &m, &y);

	printf("%02d-%02d-%d\n", d, m, y);
}
