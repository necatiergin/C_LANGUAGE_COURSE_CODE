#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: <countchars> <filename>\n");
		return 1;
	}

	FILE* f = fopen(argv[1], "r");
	if (f == NULL) {
		fprintf(stderr, "file %s cannot be opened!\n", argv[1]);
		return 2;
	}

	int letter_counts[26] = { 0 };
	int c;


	while ((c = fgetc(f)) != EOF) {
		if (isalpha(c)) {
			++letter_counts[toupper(c) - 'A'];
		}
	}

	fclose(f);

	for (int i = 0; i < 26; ++i) {
		if (letter_counts[i]) {
			printf("%c  %d\n", 'A' + i, letter_counts[i]);
		}
	}

}
