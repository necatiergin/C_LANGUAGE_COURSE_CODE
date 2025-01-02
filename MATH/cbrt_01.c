#include <math.h>
#include <stdio.h>

int main(void)
{
	const float f = 23.76123f;
	const double d = 4.3487;
	const long double ld = 87234.82794L;

	printf("cubic root of %f = %f\n", f, cbrtf(f));
	printf("cubic root of %f = %f\n", d, cbrt(d));
	printf("cubic root of %Lf = %Lf\n", ld, cbrtl(ld));
}
