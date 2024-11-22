#include <stdio.h>

int main()
{
    int a = 23, b = 37, x;

    // Original value
    x = a;
    printf("x = %d\n", x);

    // if (x == a) x = b;
    x = a ^ b ^ x;
    printf("x = %d\n", x);

    // if (x == b) x = a;
    x = a ^ b ^ x;
    printf("x = %d\n", x);

    // x = 0
    x = x ^ x;
    printf("x = %d\n", x);
}
