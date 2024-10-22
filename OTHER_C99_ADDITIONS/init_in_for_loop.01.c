#include <stdio.h>

// single-line comments since C99

int main(void)
{
	for (int i = 0; i < 10; ++i) { //since C99
		int i = 77; //valid but shadows outer i
		printf("%d\n", i);
	}

	i = 0; //error - out of scope
}
