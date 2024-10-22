#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int myprintf(const char* p, ...)
{
	va_list args;
	va_start(args, p);
	int arg_cnt = 0;

	while (*p != '\0') {
		int c = toupper(*p);
		if (c == 'I') {
			arg_cnt += printf("%d\n", va_arg(args, int));
		}
		else if (c == 'F' || c == 'D') {
			arg_cnt += printf("%f\n", va_arg(args, double));
		}
		else if (c == 'C') {
			arg_cnt += printf("%c\n", va_arg(args, int));
		}
		else if (c == 'L') {
			arg_cnt += printf("%ld\n", va_arg(args, long));
		}
		else if (c == 'U') {
			arg_cnt += printf("%u\n", va_arg(args, unsigned));
		}
		else if (c == 'S') {
			arg_cnt += printf("%s\n", va_arg(args, const char*));
		}
		++p;
	}

	va_end(args);

	return arg_cnt;
}


int main()
{
	int x = 10;
	double dval = 3.8234;
	float f = 34.7234f;
	char ch = 'A';
	char str[] = "Jiddu Krishnamurti";

	myprintf("iFdcLUS", x, f, dval, ch, 5432L, 7634U, str);

}
