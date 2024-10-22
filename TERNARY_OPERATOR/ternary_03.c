//sağdan sola öncelik yönüne dikkat

#include <stdio.h>

int main(void)
{
	int x = 1, y = 1, m;

	m = x < 5 ? y == 0 ? 4 : 6 : 8;
	//m = x < 5 ? (y == 0 ? 4 : 6) : 8;

	printf("m = %d\n", m);
}
