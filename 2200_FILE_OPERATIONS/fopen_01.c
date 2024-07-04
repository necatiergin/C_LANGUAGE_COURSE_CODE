#include <stdio.h>

int main(void)
{
	FILE* f;

	if ((f = fopen("file.txt", "r")) == NULL) {
		fprintf(stderr, "cannot open file\n");
		return 1;
	}

	printf("file opened\n");
}
