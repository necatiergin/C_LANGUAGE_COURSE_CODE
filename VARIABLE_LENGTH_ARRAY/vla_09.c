#include <stdio.h>

int main(void)
{
    int n = 3;

    int a[n++];

    printf("n = %d\n", n);          /* 4 */
    printf("%zu\n", sizeof a);      /* 3 * sizeof(int) */
}
