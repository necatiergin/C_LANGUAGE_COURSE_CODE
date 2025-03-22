#include <stdio.h>
#include <math.h>

int main() 
{
    double dval = 3.1415;
    double int_part;
    double frac_part = modf(dval, &int_part);

    printf("integer: %.0f, fraction: %.4f\n", int_part, frac_part);
}
