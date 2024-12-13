
//C99

// more efficient compiler optimization
// better documentation
// not NULL expected
// compiler may issue diagnostic (warning)

#include <stdio.h>

void func(const int p[static 10])
{
	for (int i = 0; i < 10; ++i) {
		printf("%d ", p[i]);
	}
	printf("\n");
}

int main()
{
	int ar1[7] = { 0 };
	int ar2[20] = { 0 };

	func(ar1);
	func(ar2);
}
