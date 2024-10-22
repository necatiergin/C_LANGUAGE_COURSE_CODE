#include <stdio.h>

int main()
{
	FILE* f = fopen("main.c", "rb");

	if (!f) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	fseek(f, 0L, SEEK_END);

	if (feof(f))
		printf("evet dogru\n");
	else
		printf("hayir yanlis\n");

	int c = fgetc(f);  //okuma basarisiz fgetc EOF döndürecek

	if (feof(f))
		printf("evet dogru\n");
	else
		printf("hayir yanlis\n");

	fclose(f);
}
