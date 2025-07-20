#include <stdio.h>
#include <stdlib.h>

#define    MAX_FILENAME_LEN    79

int main(int argc, char** argv)
{
	if (argc != 3) {
		printf("kullanim: <dosbol> <dosya ismi> <parca boyutu(byte)>\n");
		return 1;
	}

	FILE* fs = fopen(argv[1], "rb");
	if (!fs) {
		printf("%s dosyasi acilamadi\n", argv[1]);
		return 1;
	}

	int chunk_size	= atoi(argv[2]);
	int file_count	= 0;
	int byte_count	= 0;
	FILE* fd		= NULL;
	int ch;
	char dest_file_name[MAX_FILENAME_LEN + 1];

	while ((ch = fgetc(fs)) != EOF) {
		if (fd == NULL) { 
			sprintf(dest_file_name, "parca%03d.par", file_count + 1);
			fd = fopen(dest_file_name, "wb");
			if (!fd) {
				printf("cannot create file\n");
				_fcloseall();
				return 2;
			}
			++file_count;
		}
		fputc(ch, fd);
		++byte_count;
		if (byte_count % chunk_size == 0) {
			fclose(fd);
			fd = NULL;
		}
	}

	fclose(fs);
	if (fd)
		fclose(fd);

	printf("%d byte'lik %s dosyasi %d byte'lik %d parcaya bolundu\n",
		byte_count, argv[1], chunk_size, file_count);
}
