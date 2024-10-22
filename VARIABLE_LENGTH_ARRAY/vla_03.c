#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int dcmp(const void* vp1, const void* vp2)
{
    typedef const double* Cdptr;
    return *(Cdptr)vp2 < *(Cdptr)vp1 ? 1 :
        *(Cdptr)vp1 < *(Cdptr)vp2 ? -1 : 0;
}

double median(const double* pa, size_t size)
{
    double cpa[size];
    memcpy(cpa, pa, sizeof(*pa) * size);
    qsort(cpa, size, sizeof(*cpa), dcmp);
    return cpa[size / 2];
}

int main()
{
    double a[] = { 0.1, 8.7, 9.4, 1.2, 4.3, 0.4, 12.4, 1.9, 2.7 };

    printf("%f\n", median(a, 9));
}
