#include <stdarg.h>
#include <stdio.h>

int sum(int count, ...)
{
	int sum = 0;
	va_list args; 

	va_start(args, count);

	for (int i = 0; i < count; i++) {
		sum += va_arg(args, int);
	}

	va_end(args);

	return sum;
}

int main()
{
	int a = sum(2, 15, 20);
	int b = sum(3, 10, 15, 20);
	int c = sum(4, a, b, 10, 10);

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);

}
