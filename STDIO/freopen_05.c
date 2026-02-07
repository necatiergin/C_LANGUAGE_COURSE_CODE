#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	FILE* f = fopen("ali.txt", "w");
	if (!f) {
		fprintf(stderr, "cannot open file!");
		return 1;
	}

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; ++i) {
		fprintf(f, "%d ", rand());
	}

	fflush(f);

	if (freopen("ali.txt", "r", f) == NULL) {
		fprintf(stderr, "cannot reopen file!");
		return 2;
	}

	int x;
	while (fscanf(f, "%d", &x) != EOF)
		printf("%d\n", x);

	fclose(f);
}
