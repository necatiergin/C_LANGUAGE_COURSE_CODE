#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage <print_env>\n");
		exit(EXIT_FAILURE);
	}

	const char* pvalue;
	if ((pvalue = getenv(argv[1])) == NULL) {
		fprintf(stderr, "%s environment variable not found\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	puts(pvalue);
}
