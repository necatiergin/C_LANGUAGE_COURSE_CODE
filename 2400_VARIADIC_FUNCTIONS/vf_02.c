#define _CRT_SECURE_NO_WARNINGS

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int min(int count, ...)
{
	int min = INT_MAX;
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++) {
		int ival = va_arg(args, int);
		if (ival < min)
			min = ival;
	}
	va_end(args);

	return min;
}

int max(int count, ...)
{
	int max = INT_MIN;
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++) {
		int ival = va_arg(args, int);
		if (ival > max)
			max = ival;
	}

	va_end(args);

	return max;
}

int main()
{
	int x, y, z, t;

	printf("enter 4 integers: ");
	(void)scanf("%d%d%d%d", &x, &y, &z, &t);

	printf("min = %d\n", min(4, x, y, z, t));
	printf("max = %d\n", max(4, x, y, z, t));

}
