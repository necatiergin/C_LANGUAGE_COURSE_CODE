//find the unique element in the array. (all other elements occur twice)

#include <stdio.h>

#define asize(a)			(sizeof(a) / sizeof(*a))

int main(void)
{
	int ar[] = { 3, 7, 3, 7, 1, 9, 2, 8, 8, 2, 6, 9, 1};

	int result = 0;

	for (size_t i = 0; i < asize(ar); ++i) {
		result ^= ar[i];
	}

	printf("result = %d\n", result);
};
