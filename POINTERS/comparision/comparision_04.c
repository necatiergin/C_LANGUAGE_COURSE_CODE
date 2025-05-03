#include <stdio.h>

void PrintArray(const int* pbeg, const int* pend)
{
	while (pbeg != pend) {
		printf("%d ", *pbeg);
		++pbeg;
	}
	printf("\n------------------------------------------------\n");
}

int main(void)
{
	int ar[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	PrintArray(ar, ar + 5);
	PrintArray(ar, ar + 10);
	PrintArray(ar + 2, ar + 5);
}
