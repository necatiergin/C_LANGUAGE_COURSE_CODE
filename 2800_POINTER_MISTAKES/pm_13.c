#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    size_t n;
    printf("enter the size of the array: ");
    (void)scanf("%zu", &n);

    int* pd = (int *)malloc(n * sizeof(int));
    if (!pd) {
        printf(stderr, "cannot allocate memory: ");
        return 1;
    }

    memset(pd, 0, n * sizeof(int));
    //...
    free(pd);

    //pd is a dangling pointer now
    *pd = 123;  //ub
}
