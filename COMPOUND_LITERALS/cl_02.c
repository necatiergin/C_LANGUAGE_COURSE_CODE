#include <stdio.h>

void print_array(const int* p, size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", p[i]);
	}
}

int main(void)
{
	print_array((int[]) {2, 5, 7, 3, 6, 1}, 6);
}
