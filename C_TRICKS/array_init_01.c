#include <stdio.h>

int ar[][4] = {
	#include "init.txt"
};

int main(void)
{
	for (size_t i = 0; i < sizeof(ar) / sizeof(*ar); ++i) {
		for (int k = 0; k < 4; ++k)
			printf("%d", ar[i][k]);
		printf("\n");
	}
}
