#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void print(const char* pfmt, ...)
{
	va_list args;
	va_start(args, pfmt);

	while (*pfmt != '\0') {
		int ch = toupper(*pfmt);
		if (ch == 'D') {
			int i = va_arg(args, int);
			printf("%d\n", i);
		}
		else if (ch == 'C') {
			int c = va_arg(args, int);
			printf("%c\n", c);
		}
		else if (ch == 'F') {
			double d = va_arg(args, double);
			printf("%f\n", d);
		}
		else if (ch == 'U') {
			unsigned int uval = va_arg(args, unsigned int);
			printf("%u\n", uval);
		}
		++pfmt;
	}

	va_end(args);
}

int main(void)
{
	print("DcFfu", 3, 'a', 1.999, 42.5, 98u);
}
