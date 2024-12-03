// enc.c
// enc xyz.exe

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv)
{
	if (argc != 3) {
		fprintf(stderr, "usage: <enc> <file name> <key 8 byte long>\n");
		return 1;
	}
	FILE* fs = fopen(argv[1], "rb");
	if (!fs) {
		fprintf(stderr, "cannot open file %s\n", argv[1]);
		return 2;
	}

	char dest_filename[L_tmpnam];
	tmpnam(dest_filename);

	FILE* fd = fopen(dest_filename, "wb");
	if (!fd) {
		fclose(fs);
		fprintf(stderr, "cannot create temporary file\n");
		return 3;
	}

	long long key = atoll(argv[2]);
	srand((unsigned)key);
	int c;

	while ((c = fgetc(fs)) != EOF) {
		fputc(c ^ rand(), fd);
	}

	fclose(fs);
	fclose(fd);

	if (remove(argv[1])) {
		printf("cannot delete file\n");
		return 4;
	}

	if (rename(dest_filename, argv[1])) {
		fprintf(stderr, "dosya ismi degistirilemedi\n");
		return 5;
	}

}
