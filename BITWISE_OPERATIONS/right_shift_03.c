#include <stdio.h>

int main(void)
{
	int x = -1;

	x >>= 3;

	// true path or false path? 
	// implementation_defined

	if (x == -1) {
		printf("equal");
	}
	else {
		printf("not equal");
	}
}
