// kernighan algorithm

#include <stdio.h>

int set_bit_count(int x)
{
	int cnt = 0;

	while (x) {
		x &= x - 1;
		++cnt;
	}

	return cnt;
}

int main(void)
{
	int x;

	printf("enter an integer: ");
	scanf("%d", &x);
	printf("set bit count is : %d\n", set_bit_count(x));
}
