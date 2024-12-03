#include <stdio.h>

int main(void)
{
	FILE* f = fopen("output.txt", "w");
	if (!f) {
		fprintf(stderr, "cannot create file\n");
		return 1;
	}

	for (int i = 'A'; i <= 'Z'; ++i) {
		fputc(i, f);
	}
	
	fputc('\n', f);

	for (int i = 'a'; i <= 'z'; ++i) {
		fputc(i, f);
	}
	
	fputc('\n', f);

	for (int i = '0'; i <= '9'; ++i) {
		fputc(i, f);
	}
	
	fclose(f);
}
