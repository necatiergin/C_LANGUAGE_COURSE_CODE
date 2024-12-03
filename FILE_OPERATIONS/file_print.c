// fileprint neco.txt

#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: <fileprint> <filename>\n");
		return 1;
	}


	FILE* f = fopen(argv[1], "r");
	if (f == NULL) {
		fprintf(stderr, "cannot open file to read!\n");
		return 2;
	}

	int c;

	while ((c = fgetc(f)) != EOF) {
		putchar(c);
	}

	fclose(f);	
}
