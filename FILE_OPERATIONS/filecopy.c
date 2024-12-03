// copyfile ali.xyz   mehmet.xyz

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if (argc != 3) {
		fprintf(stderr, "usage: <copyfile> <source file name> <dest file name>\n");
		return 1;
	}

	FILE* fs = fopen(argv[1], "rb");
	if (!fs) {
		fprintf(stderr, "cannot open file %s\n", argv[1]);
		return 2;
	}

	FILE* fd = fopen(argv[2], "wb");
	if (!fd) {
		fprintf(stderr, "cannot create file %s\n", argv[2]);
		fclose(fs);
		return 3;
	}

	int c;
	int byte_count = 0;
	while ((c = fgetc(fs)) != EOF) {
		fputc(c, fd);
		++byte_count;
	}

	fclose(fs);
	fclose(fd);

	printf("file %s of %d bytes copied as file %s\n", argv[1], byte_count, argv[2]);
}
