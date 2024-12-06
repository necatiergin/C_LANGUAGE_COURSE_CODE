#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* concat(const char* ptr, ...)
{
	va_list args1, args2;

	va_start(args1, ptr);
	va_copy(args2, args1);
	const char* p;

	size_t len = strlen(ptr);
	while ((p = va_arg(args1, const char*)) != NULL)
		len += strlen(p);

	char* pd = (char*)malloc(len + 1);
	if (!pd) {
		fprintf(stderr, "cannot allocate memory\n");
		exit(EXIT_FAILURE);
	}
	va_end(args1);

	strcpy(pd, ptr);

	while ((p = va_arg(args2, const char*)) != NULL)
		strcat(pd, p);

	va_end(args2);

	return pd;
}

int main(void)
{
	char* p = concat("necati ", "ergin ", "kaan ", "aslan", NULL);

	puts(p);
	free(p);
}
