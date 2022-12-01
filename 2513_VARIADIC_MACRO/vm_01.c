#include <stdio.h>

#define  eprintf(...)  fprintf(stderr, __VA_ARGS__)

int main(void)
{
	int x = 10, y = 20;
	double dval = 45.6;

	eprintf("hata : x = %d y = %d dval = %f\n", x, y, dval);
}
