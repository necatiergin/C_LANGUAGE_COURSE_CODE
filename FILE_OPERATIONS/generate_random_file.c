// generate random file
// grfile ufuk.txt  10000  40  70

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void randomize(void)
{
	srand((unsigned)(time(NULL)));
}

int get_random_char(void)
{
	int ch;

	while (!isalnum(ch = rand() % 128))
		;

	return ch;
}

int main(int argc, char** argv)
{
	if (argc != 5) {
		fprintf(stderr, "usage: <grfile> <filename> <no of lines> <min line length> <max line length>\n");
		return 1;
	}

	int line_count = atoi(argv[2]);
	int min_line_len = atoi(argv[3]);
	int max_line_len = atoi(argv[4]);

	FILE* f = fopen(argv[1], "w");
	if (!f) {
		fprintf(stderr, "cannot create file %s\n", argv[1]);
		return 2;
	}

	randomize();

	for (int i = 0; i < line_count; ++i) {
		int linelen = rand() % (max_line_len - min_line_len + 1) + min_line_len;
		while (linelen-- > 0) {
			fputc(get_random_char(), f);
		}
		fputc('\n', f);
	}

	fclose(f);
}
