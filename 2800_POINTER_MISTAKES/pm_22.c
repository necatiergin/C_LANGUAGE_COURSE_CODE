#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void allocate_memory(char* p, size_t n)
{
	p = (char*)malloc(n);
	if (!p) {
		fprintf(stderr, "cannot allocate memory!\n");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	char* ptr;

	allocate_memory(ptr, 100);
	strcpy(ptr, "avoid pointer mistakes!");
	puts(ptr);
	free(ptr);
}
