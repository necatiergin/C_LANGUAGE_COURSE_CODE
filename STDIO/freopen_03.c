#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* f;

	if ((f = freopen("test.txt", "w", stdout)) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 10; ++i)
		printf("%d\n", i);

	fclose(f);
}
