#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* f;

	if ((f = freopen("input.txt", "r", stdin)) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	int c;
	while ((c = getchar()) != EOF)
		putchar(c);

	fclose(f);
}
