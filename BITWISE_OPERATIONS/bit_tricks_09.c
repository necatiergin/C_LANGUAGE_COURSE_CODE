// to get min and max without branching

#include <stdio.h>

int main()
{
    int x, y;
    
    printf("enter two integers: ");
    (void)scanf("%d%d", &x, &y);

    int min = (y ^ (x ^ y) & -(x < y));
    int max = (x ^ (x ^ y) & -(x < y));

    printf("min(%d, %d) => %d\n", x, y, min);
    printf("max(%d, %d) => %d\n", x, y, max);
}
