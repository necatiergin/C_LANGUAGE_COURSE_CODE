#include <ctype.h>
#include <stdio.h>

int main(void)
{
	printf("isupper\n");
	for (int i = 0; i < 128; ++i) {
		if (isupper(i))
			putchar(i);
	}
	printf("\n\n");

	printf("islower\n");
	for (int i = 0; i < 128; ++i) {
		if (islower(i))
			putchar(i);
	}
	printf("\n\n");


	printf("isalpha\n");
	for (int i = 0; i < 128; ++i) {
		if (isalpha(i))
			putchar(i);
	}
	printf("\n\n");

	printf("isdigit\n");
	for (int i = 0; i < 128; ++i) {
		if (isdigit(i))
			putchar(i);
	}
	printf("\n\n");


	printf("isalnum\n");
	for (int i = 0; i < 128; ++i) {
		if (isalnum(i))
			putchar(i);
	}
	printf("\n\n");

	printf("isxdigit\n");
	for (int i = 0; i < 128; ++i) {
		if (isxdigit(i))
			putchar(i);
	}
	printf("\n\n");

	printf("ispunct\n");
	for (int i = 0; i < 128; ++i) {
		if (ispunct(i))
			putchar(i);
	}
	printf("\n\n");

	printf("isprint\n");
	for (int i = 0; i < 128; ++i) {
		if (isprint(i))
			putchar(i);
	}
	printf("\n\n");

	printf("isgraph\n");
	for (int i = 0; i < 128; ++i) {
		if (isgraph(i))
			putchar(i);
	}
	printf("\n\n");

	printf("isspace\n");
	for (int i = 0; i < 128; ++i) {
		if (isspace(i))
			printf("%d ", i);
	}
	printf("\n\n");


	printf("isblank\n");
	for (int i = 0; i < 128; ++i) {
		if (isblank(i))
			printf("%d ", i);
	}
	printf("\n\n");


	printf("iscntrl\n");
	for (int i = 0; i < 128; ++i) {
		if (iscntrl(i))
			printf("%d ", i);
	}
}
