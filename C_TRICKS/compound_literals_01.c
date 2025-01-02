#include <stdio.h>

int sum(const int* values)
{
    int sum = 0;

    while (*values)
        sum += *values++;

    return sum;
}

int main(void)
{
    printf("%d\n", sum((int[]) { 3, 6, 9, 0 }));
}
