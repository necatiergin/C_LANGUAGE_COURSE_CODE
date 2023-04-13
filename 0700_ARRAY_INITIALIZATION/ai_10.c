#include <stdio.h>

#define  SIZE		10

int a[SIZE];  //zero init.


void func(void)
{
	static int ar[SIZE]; //zero init.

	for (int i = 0; i < SIZE; ++i) {
		printf("%d ", ar[i]);
	}
}

int main(void)
{
	func();
	printf("\n");

	for (int i = 0; i < SIZE; ++i) {
		printf("%d ", a[i]);
	}
}
